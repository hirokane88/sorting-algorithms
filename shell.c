#include "shell.h"
#include "gaps.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

uint64_t s_moves = 0;
uint64_t s_compares = 0;

void shell_sort(uint32_t *A, uint32_t n) {
  uint32_t g_i = 0;
  uint32_t swap = 0;

  while (gaps[g_i] > 0) {
    uint32_t gap = gaps[g_i];

    for (uint32_t i = gap; i < n; i++) {
      uint32_t temp = A[i];
      uint32_t j = i;

      s_compares++;
      while (j >= gap && temp < A[j - gap]) {
        swap = A[j];
        A[j] = A[j - gap];
        A[j - gap] = swap;
        j -= gap;

        s_moves += 3;
        s_compares++;
      }
      A[j] = temp;
    }
    g_i++;
  }
}
