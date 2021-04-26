#include "stack.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct Stack {
  uint32_t top;
  uint32_t capacity;
  uint64_t *items;
};

struct Stack *stack_create() {

  struct Stack *s = (struct Stack *)calloc(1, sizeof(struct Stack));
  s->top = 0;
  s->capacity = MIN_CAPACITY;
  s->items = (uint64_t *)calloc(s->capacity, sizeof(uint64_t));
  return s;
}

void stack_delete(struct Stack **s) {
  free((*s)->items);
  free(*s);
  *s = NULL;
}

uint32_t stack_size(Stack *s) { return s->top; }

bool stack_empty(struct Stack *s) { return s->top == 0; }

bool stack_push(Stack *s, int64_t x) {
  if (s->top == s->capacity) {
    s->capacity *= 2;
    uint64_t *temp = realloc(s->items, s->capacity * sizeof(int64_t));
    if (temp == NULL) {
      return false;
    } else {
      s->items = temp;
    }
  }
  s->items[s->top] = x;
  s->top++;
  return true;
}

bool stack_pop(Stack *s, int64_t *x) {
  s->top--;
  *x = s->items[s->top];
  return true;
}

void stack_print(Stack *s) {
  for (uint32_t i = 0; i < s->capacity; i++) {
    printf("%lu ", s->items[i]);
  }
}
