#include "arrays.h"

int max(int array[], size_t dim) {

  int max_value = array[0];

  for(size_t i = 1; i < dim; i++) {
    if(array[i] > max_value) {
      max_value = array[i];
    }
  }
  return max_value;
}





