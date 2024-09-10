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


Test(arrays, initialize_range, .init = setup) {
  int one_expected[] = {0};
  int five_expected[] = {0, 1, 2, 3, 4};
  int lots_expected[size];
  for (size_t i = 0; i < size; ++i) {
    lots_expected[i] = i;
  }

  initialize_range(empty, 0);  // must not crash
  initialize_range(one, 1);
  initialize_range(five, 5);
  initialize_range(lots, size);

  cr_assert(eq(int[1], one, one_expected));
  cr_assert(eq(int[5], five, five_expected));
  cr_assert(eq(int[size], lots, lots_expected));
}


Test(arrays, minimum, .init = setup) {

  cr_assert(eq(int, min(one, 1), 3));
  cr_assert(eq(int, min(five, 5), 5));
  cr_assert(eq(int, min(lots, size), 0));
}


Test(arrays, minimum_negative, .init = setup) {
  cr_assert(eq(int, min(negative, 3), -9));
}


Test(arrays, maximum, .init = setup) {

  cr_assert(eq(int, max(one, 1), 3));
  cr_assert(eq(int, max(five, 5), 9));
  cr_assert(eq(int, max(lots, size), (size - 1) * (size - 1)));
}


Test(arrays, maximum_negative, .init = setup) {
  cr_assert(eq(int, max(negative, 3), -5));
}


Test(arrays, average, .init = setup) {
  for (size_t i = 0; i < size; ++i) {
    lots[i] = i;
  }
  cr_assert(eq(dbl, average(one, 1), 3.0));
  cr_assert(eq(dbl, average(five, 5), 7.0));
  cr_assert(eq(dbl, average(lots, size), (size - 1) / 2.0));
  cr_assert(eq(dbl, average(negative, 3), -7.0));
}
