#include "fraction.h"
#include <algorithm>
#include <iostream>
#include <math.h>
using std::cout;
using std::endl;
using std::to_string;

int main() {

  // creating a few fractions:
  Fraction half(1, 2);
  Fraction third(1, 3);

  // testing out operations:
  bool lessThan = half < third;
  bool greaterThan = half > third;
  cout << "half is less than third: " << lessThan << endl;
  cout << "half is greater than third: " << greaterThan << endl;

  // non-member functions
  // bool piLessThan = M_PI < third;
  // cout << "pi less than a third: " << piLessThan << endl;

  return 0;
}
