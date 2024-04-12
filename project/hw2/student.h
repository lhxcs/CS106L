#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

// define Student Class
class Student {
public:
    void SetNumber(int lineNum);
    void SetName(std::string name);
    void SetCourse(std::string courseName, int score);
    void Print();
private:
    int num;
    std::string name;
    struct Course {
        int score;
        std::string courseName;
    };
    std::vector<Course> courses;
};

#endif