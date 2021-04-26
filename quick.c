#include "quick.h"
#include "stack.h"
#include <stdio.h>

uint64_t q_moves = 0;
uint64_t q_compares = 0;

int64_t partition(uint32_t *arr, int64_t lo, int64_t hi) {

  int64_t pivot = arr[lo + ((hi - lo) / 2)];
  int64_t ascent = lo - 1;
  int64_t descent = hi + 1;
  int64_t temp = 0;
  while (ascent < descent) {
    ascent++;
    q_compares++;
    while (arr[ascent] < pivot) {
      q_compares++;
      ascent++;
    }
    descent--;
    q_compares++;
    while (arr[descent] > pivot) {
      q_compares++;
      descent--;
    }
    if (ascent < descent) {
      temp = arr[ascent];
      arr[ascent] = arr[descent];
      arr[descent] = temp;
      q_moves += 3;
    }
  }
  return descent;
}

void quick_sort(uint32_t *A, uint32_t n) {

  uint32_t left = 0;
  uint32_t right = n - 1;

  int64_t hi = 0;
  int64_t lo = 0;
  int64_t p = 0;

  Stack *stack = stack_create();
  stack_push(stack, left);
  stack_push(stack, right);

  while (stack_empty(stack) == false) {
    stack_pop(stack, &hi);
    stack_pop(stack, &lo);

    p = partition(A, lo, hi);

    if ((p + 1) < hi) {
      stack_push(stack, (p + 1));
      stack_push(stack, hi);
    }
    if (p > lo) {
      stack_push(stack, lo);
      stack_push(stack, p);
    }
  }
}
