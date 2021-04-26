#include <stdbool.h>
#include <stdint.h>

typedef uint32_t Set;

Set set_empty(void) {
  uint8_t r = 0;
  return r;
}

bool set_member(Set s, uint8_t x) {
  uint8_t mask = 1 << x;
  return (s & mask) != 0;
}

Set set_insert(Set s, uint8_t x) {
  uint8_t mask = 1 << x;
  return s | mask;
}

Set set_remove(Set s, uint8_t x) {
  uint8_t mask = ~(1 << x);
  return s & mask;
}

Set set_intersect(Set s, Set t) { return s & t; }

Set set_union(Set s, Set t) { return s | t; }

Set set_complement(Set s) { return ~s; }

Set set_difference(Set s, Set t) { return s & ~t; }
