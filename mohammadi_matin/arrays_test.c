#include "arrays.h"

#include <criterion/criterion.h>
#include <criterion/new/assert.h>

#include <stddef.h>

enum { size = 123 };

int empty[0] = {};
int one[1];
int five[5];
int lots[size];
int negative[3];



// Run before each test.
void setup(void) {
  one[0] = 3;

  five[0] = 5;
  five[1] = 6;
  five[2] = 7;
  five[3] = 8;
  five[4] = 9;

  for (size_t i = 0; i < size; ++i) {
    lots[i] = i * i;
  }

  negative[0] = -7;
  negative[1] = -5;
  negative[2] = -9;
}


Test(arrays, maximum, .init = setup) {

  cr_assert(eq(int, max(one, 1), 3));
  cr_assert(eq(int, max(five, 5), 9));
  cr_assert(eq(int, max(lots, size), (size - 1) * (size - 1)));
}


Test(arrays, maximum_negative, .init = setup) {
  cr_assert(eq(int, max(negative, 3), -5));
}

