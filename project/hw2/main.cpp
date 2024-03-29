#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <map>
#include <sstream>
#include <memory>
#include <algorithm>

#include "student.h"

#define PRINTWIDTH 10

extern std::vector<std::string> firstLine;
extern std::vector<int> courseMax;
extern std::vector<int> courseMin;
extern std::vector<int> courseSum;
extern std::vector<int> courseCount;

// Initialize course statistics vectors with default values
void initial() {
    for (size_t i = 0; i < firstLine.size(); i++) {
        courseMax.push_back(0);
        courseMin.push_back(100);
        courseSum.push_back(0);
        courseCount.push_back(0);
    }
}

int main() {
    std::vector<std::unique_ptr<Student>> students; // Vector to store student objects
    firstLine.push_back("no");
    firstLine.push_back("name");

    std::ifstream iss("students.txt");
    if (!iss.is_open()) {
        std::cerr << "Fail to open file" << std::endl;
        return 1;
    }

    int lineNum = 1;
    std::string line;
    while (std::getline(iss, line)) { // Read each line from the input file
        std::istringstream ss(line);
        std::string name;
        ss >> name;
        std::unique_ptr<Student> ptr(new Student);
        ptr->SetName(name);
        ptr->SetNumber(lineNum);

        std::string courseName;
        int score;
        while (ss >> courseName >> score) { // Read course name and score pairs
            ptr->SetCourse(courseName, score);
            if (std::find(firstLine.begin(), firstLine.end(), courseName) == firstLine.end()) {
                firstLine.push_back(courseName);  // Add course name to the firstLine vector if not already present
            }
        }

        lineNum++;
        students.push_back(std::move(ptr)); // Add student object to the vector
    }

    initial();
    firstLine.push_back("average");

    // Print the header line
    for (const auto& name : firstLine) {
        std::cout << std::left << std::setw(PRINTWIDTH) << name;
    }
    std::cout << std::endl;

    // Print student details
    for (const auto& student : students) {
        student->Print();
    }

    // Print average score for each course
    std::cout << "          ";
    std::cout << std::left << std::setw(PRINTWIDTH) << "average";
    for (size_t k = 2; k < firstLine.size() - 1; k++) {
        if (!courseCount[k]) {
            std::cout << "          ";
        } else {
            std::cout << std::left << std::setw(PRINTWIDTH) << std::fixed << std::setprecision(1)
                      << static_cast<double>(courseSum[k]) / courseCount[k];
        }
    }
    std::cout << std::endl;

    // Print maximum score for each course
    std::cout << "          ";
    std::cout << std::left << std::setw(PRINTWIDTH) << "max";
    for (size_t k = 2; k < firstLine.size() - 1; k++) {
        if (!courseCount[k]) {
            std::cout << "          ";
        } else {
            std::cout << std::left << std::setw(PRINTWIDTH) << courseMax[k];
        }
    }
    std::cout << std::endl;

    // Print minimum score for each course
    std::cout << "          ";
    std::cout << std::left << std::setw(PRINTWIDTH) << "min";
    for (size_t k = 2; k < firstLine.size() - 1; k++) {
        if (!courseCount[k]) {
            std::cout << "          ";
        } else {
            std::cout << std::left << std::setw(PRINTWIDTH) << courseMin[k];
        }
    }
    std::cout << std::endl;

    iss.close();
    return 0;
}
