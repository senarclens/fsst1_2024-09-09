#include "arrays.h"
#include <stdio.h>
int max(int array[],size_t dim) {
int max=array[0];
for(size_t i=1;i<dim;i++) {
  if(array[i]>max) {
    max=array[i];
  }
}
return max;

}
