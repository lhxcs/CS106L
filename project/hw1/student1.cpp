#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>

//Struct to represent a student
struct Student{
    std::string name;
    float score[3];
    float average;
};


//Function prototypes
void read_students(std::string filename, std::vector<Student>& students);
void print_students(const std::vector<Student>& students);
void print_average_min_max_score(const std::vector<Student>& students);

int main() {
    std::vector<Student> students; // store student datas
    read_students("students.txt", students);
    print_students(students);
    print_average_min_max_score(students);
}

// Read student data from file
void read_students(std::string filename, std::vector<Student>& students) {
    std::ifstream file(filename);
    std::string name;
    float score1, score2, score3;
    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
    }
    while(file >> name >> score1 >> score2 >> score3) {
        Student student;
        student.name = name;
        student.score[0] = score1;
        student.score[1] = score2;
        student.score[2] = score3;
        student.average = (score1 + score2 + score3) / 3; // Calculate the average score
        students.push_back(student);
    }
    file.close();
}

// Print student data to console
void print_students(const std::vector<Student>& students) {
    std::cout << "no\tname\tscore1\tscore2\tscore3\taverage" << std::endl;
    int no = 1;
    for (auto student : students) {
        std::cout << no++ << "\t" << student.name << "\t" << student.score[0] << "\t" << student.score[1] << "\t" << student.score[2] << "\t" << student.average << std::endl;
    }
}

// Calculate and print the average, min and max scores
void print_average_min_max_score(const std::vector<Student>& students) {
    float total[3] = {0};
    float mins[3] = {__FLT_MAX__, __FLT_MAX__, __FLT_MAX__};
    float maxs[3] = {0, 0, 0};
    for (auto student : students) {
        for (int i = 0; i < 3; ++i) {
            total[i] += student.score[i];
            mins[i] = std::min(mins[i], student.score[i]);
            maxs[i] = std::max(maxs[i], student.score[i]);
        }
    }
    std::cout << "\taverage\t" << total[0] / students.size() << "\t" << total[1] / students.size() << "\t" << total[2] / students.size() << std::endl;
    std::cout << "\tmin\t" << mins[0] << "\t" << mins[1] << "\t" << mins[2] << std::endl;
    std::cout << "\tmax\t" << maxs[0] << "\t" << maxs[1] << "\t" << maxs[2] << std::endl;
}