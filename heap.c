#include "heap.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

uint64_t h_moves = 0;
uint64_t h_compares = 0;

uint32_t max_child(uint32_t *arr, uint32_t first, uint32_t last) {
  uint32_t left = 2 * first;
  uint32_t right = left + 1;
  h_compares++;
  if ((right <= last) && (arr[right - 1] > arr[left - 1])) {
    return right;
  }
  return left;
}

void fix_heap(uint32_t *arr, uint32_t first, uint32_t last) {
  uint32_t found = false;
  uint32_t parent = first;
  uint32_t great = max_child(arr, parent, last);
  uint32_t temp = 0;

  while ((parent <= (last / 2)) && (found == false)) {
    h_compares++;
    if (arr[parent - 1] < arr[great - 1]) {
      temp = arr[parent - 1];
      arr[parent - 1] = arr[great - 1];
      arr[great - 1] = temp;
      h_moves += 3;

      parent = great;
      great = max_child(arr, parent, last);
    } else {
      found = true;
    }
  }
}

void build_heap(uint32_t *arr, uint32_t first, uint32_t last) {
  uint32_t hlast = last / 2;
  for (uint32_t parent = hlast; parent > first - 1; parent--) {
    fix_heap(arr, parent, last);
  }
}

void heap_sort(uint32_t *A, uint32_t n) {
  uint32_t first = 1;
  uint32_t last = n;
  uint32_t temp = 0;

  build_heap(A, first, last);
  for (uint32_t leaf = last; leaf > first; leaf--) {
    temp = A[first - 1];
    A[first - 1] = A[leaf - 1];
    A[leaf - 1] = temp;
    h_moves += 3;
    fix_heap(A, first, leaf - 1);
  }
}
