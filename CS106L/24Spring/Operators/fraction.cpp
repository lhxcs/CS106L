// system
#include <iostream>
#include <algorithm>
#include <math.h>
#include "fraction.h"

using std::cout;    using std::endl;
using std::to_string;

// constructor to initialize Fraction
Fraction::Fraction (int num, int denom) {
    this->num = num;
    this->denom = denom;
    reduce();
}

void Fraction::reduce() {
    int gcd = std::__gcd(num, denom);
    num /= gcd;
    denom /= gcd;
}

// return if fraction represented by this is less than rhs
bool Fraction::operator < (const Fraction& rhs) const {
    return rhs.denom * num < rhs.num * denom;
}

// return if fraction represented by this is greater than rhs
bool Fraction::operator > (const Fraction& rhs) const {
    return rhs.denom * num > rhs.num * denom;
}

// get difference of this and rhs fractions
Fraction Fraction::operator - (const Fraction& rhs) const {
    int newNum = num * rhs.denom - denom * rhs.num;    
    int newDenom = rhs.denom * denom;
    return Fraction(newNum, newDenom);
}

// non-member functions:
// Implementing the += operation in a non-member function
Fraction& operator += (Fraction& lhs, const Fraction& rhs) {
    lhs.num = lhs.num * rhs.denom + lhs.denom * rhs.num;    
    lhs.denom *= rhs.denom;
    lhs.reduce();
    return lhs;
}

// Implementing the * operation in a non-member function
bool operator < (const double& lhs, const Fraction& rhs) {
    double frac = rhs.num / rhs.denom;
    return lhs < frac;
}

// Overloading << to allow for passing Fractions into streams.
std::ostream& operator << (std::ostream& out, const Fraction& target) {
    out << target.num << "/" << target.denom;
    return out;
}

