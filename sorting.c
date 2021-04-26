#include "bubble.h"
#include "heap.h"
#include "quick.h"
#include "set.h"
#include "shell.h"
#include <inttypes.h>
#include <ncurses.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define DEFAULT_SEED 7092016
#define DEFAULT_ARR_SIZE 100
#define DEFAULT_ELEMENTS 100
#define THIRTY_BITS 1073741823

typedef enum sort { bubble = 0, shell = 1, quick = 2, heap = 3 } Dog;

int main(int argc, char **argv) {

  Set sorts = set_empty();
  int seed = DEFAULT_SEED;
  int arr_size = DEFAULT_ARR_SIZE;
  int elements = DEFAULT_ELEMENTS;

  int opt = 0;
  while ((opt = getopt(argc, argv, "absqhrnp")) != -1) {
    switch (opt) {
    case 'a':
      sorts = set_insert(sorts, bubble);
      sorts = set_insert(sorts, shell);
      sorts = set_insert(sorts, quick);
      sorts = set_insert(sorts, heap);
      break;
    case 'b':
      sorts = set_insert(sorts, bubble);
      break;
    case 's':
      sorts = set_insert(sorts, shell);
      break;
    case 'q':
      sorts = set_insert(sorts, quick);
      break;
    case 'h':
      sorts = set_insert(sorts, heap);
      break;
    case 'r':
      if (argv[optind] == NULL) {
        break;
      }
      if ((atoi(argv[optind]) == 0) && (strcmp(argv[optind], "0"))) {
        break;
      } else {
        seed = atoi(argv[optind]);
        break;
      }
    case 'n':
      if (argv[optind] == NULL) {
        break;
      }
      if ((atoi(argv[optind]) == 0) && (strcmp(argv[optind], "0"))) {
        break;
      } else {
        arr_size = atoi(argv[optind]);
        break;
      }
    case 'p':
      if (argv[optind] == NULL) {
        break;
      }
      if ((atoi(argv[optind]) == 0) && (strcmp(argv[optind], "0"))) {
        break;
      } else {
        elements = atoi(argv[optind]);
        break;
      }
    default:
      fprintf(stderr, "Usage: %s -[absqhrnp]\n", argv[0]);
      exit(1);
    }
  }

  extern uint64_t b_moves;
  extern uint64_t s_moves;
  extern uint64_t q_moves;
  extern uint64_t h_moves;
  extern uint64_t b_compares;
  extern uint64_t s_compares;
  extern uint64_t q_compares;
  extern uint64_t h_compares;

  srandom(seed);
  uint32_t b_array[arr_size];
  uint32_t s_array[arr_size];
  uint32_t q_array[arr_size];
  uint32_t h_array[arr_size];
  uint32_t arr_val;
  uint32_t mask = THIRTY_BITS;
  int max = elements;

  for (int i = 0; i < arr_size; i++) {
    arr_val = random() & mask;
    b_array[i] = arr_val;
    s_array[i] = arr_val;
    q_array[i] = arr_val;
    h_array[i] = arr_val;
  }

  if (arr_size < max) {
    max = arr_size;
  }

  for (int s = bubble; s <= heap; s++) {
    if (set_member(sorts, s)) {

      switch (s) {

      case bubble:
        bubble_sort(b_array, arr_size);
        printf("Bubble Sort\n");
        printf("%d elements, %ld moves, %ld compares\n", arr_size, b_moves,
               b_compares);
        if (max == 0) {
          break;
        }

        for (int i = 0; i < max; i++) {
          if (i % 5 == 0 && i != 0) {
            printf("\n");
          }
          printf("%13" PRIu32, b_array[i]);
        }
        printf("\n");
        break;

      case shell:
        shell_sort(s_array, arr_size);
        printf("Shell Sort\n");
        printf("%d elements, %ld moves, %ld compares\n", arr_size, s_moves,
               s_compares);
        if (max == 0) {
          break;
        }

        for (int i = 0; i < max; i++) {
          if (i % 5 == 0 && i != 0) {
            printf("\n");
          }
          printf("%13" PRIu32, s_array[i]);
        }
        printf("\n");
        break;

      case quick:
        quick_sort(q_array, arr_size);
        printf("Quick Sort\n");
        printf("%d elements, %ld moves, %ld compares\n", arr_size, q_moves,
               q_compares);
        if (max == 0) {
          break;
        }

        for (int i = 0; i < max; i++) {
          if (i % 5 == 0 && i != 0) {
            printf("\n");
          }
          printf("%13" PRIu32, q_array[i]);
        }
        printf("\n");
        break;

      case heap:
        heap_sort(h_array, arr_size);
        printf("Heap Sort\n");
        printf("%d elements, %ld moves, %ld compares\n", arr_size, h_moves,
               h_compares);
        if (max == 0) {
          break;
        }

        for (int i = 0; i < max; i++) {
          if (i % 5 == 0 && i != 0) {
            printf("\n");
          }
          printf("%13" PRIu32, h_array[i]);
        }
        printf("\n");
        break;

      default:
        break;
      }
    }
  }

  exit(1);
}
