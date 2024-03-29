#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>
#include <iomanip>
#include "student.h"

#define PRINTWIDTH 10

using std::vector;
using std::string;
using std::cout; using std::endl;

vector<string> firstLine; // vector to store the first line of the input file
vector<int> courseMax;
vector<int> courseMin;
vector<int> courseSum;
vector<int> courseCount;

void Student::SetCourse(string courseName, int score) {
    Course course;
    course.courseName = courseName;
    course.score = score;
    this->courses.push_back(course);
}

void Student::SetName(string name) {
    this->name = name;
}

void Student::SetNumber(int num) {
    this->num = num;
}

void Student::Print() {
    // Print student number and name
    cout << std::left << std::setw(PRINTWIDTH) << num;
    cout << std::left << std::setw(PRINTWIDTH) << name;

    // Iterate over course names and print scores
    for (size_t j = 2; j < firstLine.size() - 1; j++) {
        int flag = 0;
        for(size_t i = 0 ; i < this->courses.size(); i++) {
            if(this->courses[i].courseName == firstLine[j]) {
                cout << std::left << std::setw(PRINTWIDTH) << this->courses[i].score;
                if(courseMax[j] < this->courses[i].score) {
                    courseMax[j] = this->courses[i].score;
                }
                if(courseMin[j] > this->courses[i].score) {
                    courseMin[j] = this->courses[i].score;
                }
                courseSum[j] += this->courses[i].score;
                courseCount[j]++; // Update max, min, sum, and count for each course
                flag = 1;
                i++;
                break;
            }
        }
        if(!flag) {
                cout << "          ";
            }
    }

    // Calculate and print the average score for the student
    double tol = 0;
    for(size_t i = 0; i < this->courses.size(); i++) {
        tol += this->courses[i].score;
    }
    tol /= this->courses.size();
    cout << std::left << std::setw(PRINTWIDTH) << std::fixed <<std::setprecision(5) << tol;
    cout << endl;
}


