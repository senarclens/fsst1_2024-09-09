#include <math.h>
#include <stdio.h>
double area(double radius) {
  double area = M_PI;
  double n = radius * radius;
  return n * area;

double circumference(double radius) {
  double pi=M_PI;
  int i=2:
  return i*radius*pi;
}


}// provides M_PI
// Ergänze fehlende Header


// Hier sollen beide Funktionen definiert werden.


int main() {
  double radius = 5;
  printf("Der Umfang beträgt %lf m.\n", circumference(5));
  printf("Die Fläche beträgt %lf m2.\n", area(5));
  return 0;
}

