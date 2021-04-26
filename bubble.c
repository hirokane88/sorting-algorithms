#include "bubble.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

uint64_t b_moves = 0;
uint64_t b_compares = 0;

void bubble_sort(uint32_t *A, uint32_t n) {

  uint32_t temp = 0;
  uint32_t swapped = true;

  while (swapped) {
    swapped = false;
    for (uint32_t i = 1; i < n; i++) {
      b_compares++;
      if (A[i] < A[i - 1]) {
        temp = A[i];
        A[i] = A[i - 1];
        A[i - 1] = temp;
        b_moves += 3;
        swapped = true;
      }
    }
    n--;
  }
}
