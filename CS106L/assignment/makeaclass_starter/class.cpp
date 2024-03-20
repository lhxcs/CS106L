// Blank cpp file
#include "class.h"

myClass::myClass(std::string name, std::string food, std::string major, int age)
    : name{name}, food{food}, major{major}, age{age} {}


std::string myClass::getName() { return this->name; }

std::string myClass::getFood() { return this->food; }

std::string myClass::getMajor() { return this->major; }

int myClass::getAge() { return this->age; }

void myClass::setName(std::string name) { this->name = name; }

void myClass::setFood(std::string food) { this->food = food; }

void myClass::setMajor(std::string major) { this->major = major; }

void myClass::setAge(int age) { 
  if ( age >= 0) {
    this->age = age;
  }
}

myClass::~myClass(){};