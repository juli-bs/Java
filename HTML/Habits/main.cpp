#include <iostream>

using std::cout;
using std::endl;

#include <math.h>

using std::pow;


double a(double x) {

   return 1 / x + pow(-1, x) * 1 / x + 1 / x;

}

double S(double x) {

   double sum = 0;

   for(int i = 1; i <=x; i++) {

      sum += a(i);

   }

   return sum;

}

int main() {
/*
   for(int i = 1; i <= 2000; i++) {

      cout << S(i) << endl;

   }
*/
   for(int i = 1; i <= 3; i++) {
      cout << a(i) << endl;
   }

   return 0;

}