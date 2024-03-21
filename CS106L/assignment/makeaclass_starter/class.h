// Blank header file
#ifndef CLASS_H
#define CLASS_H
#include <string>

class myClass {
private:
    using String = std::string;
    String name;
    String food;
    String major;
    int age;
public:
    myClass() {
        name = "NULL";
        food = "NULL";
        major = "NULL";
        age = 0;
    }
    myClass(String name, String food, String major, int age);
    ~myClass();
    String getName();
    String getFood();
    String getMajor();
    int getAge();

    void setName(std::string name);
    void setFood(std::string food);
    void setMajor(std::string major);
    void setAge(int age);

};

#endif