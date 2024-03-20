#include "class.h"
#include "class.cpp"
#include <string>
#include <iostream>

/*
 * Assigment 3: Make a class!
 * Requirements:
 * Must have a custom constructor ❌
 * Must have a default constructor ❌
    - i.e. constructor overloading
 * Must have private members (functions and/or variables) ❌
 * Must have public members (functions) ❌
 * Must have at least one getter function ❌
 * Must have at least one setter function ❌
 */

int main() {
  // initialize class and run this file
  auto s = myClass("lhx", "McDonalds", "CS", 19);
  std::cout << s.getName() << std::endl;
  std::cout << s.getFood() << std::endl;
  std::cout << s.getMajor() << std::endl;
  std::cout << s.getAge() << std::endl;
  s.setFood("KFC");
  std::cout << s.getFood() << std::endl;

}