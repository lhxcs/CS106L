/* 
Assignment 2: Marriage Pact

This assignment asks you to discover your one true love using containers and pointers.
There are two parts: implement get_applicants and find_matches.

Submit to Paperless by 11:59pm on 2/1/2024.
*/

#include <iostream>
#include<fstream>
#include <string>
#include<sstream>
#include <queue>
#include <set>

std::set<std::string> get_applicants(std::string filename) {
    // TODO: Implement this function. Feel free to change std::set to std::unordered_set if you wish!
    std::ifstream file(filename);
    if( !file.is_open() ) {
        std::cerr << "Failed to open file!" << std::endl;
    }
    std::string name;
    std::set<std::string> applicants;
    while(std::getline(file, name)) {
        applicants.insert(name);
    }
    return applicants;
}

std::queue<std::string*> find_matches(std::set<std::string> &students) {
    // TODO: Implement this function.
    std::queue<std::string*> match;
    for(const std::string& student : students) {
        std::istringstream iss (student);
        std::string first;
        std::string last;
        iss >> first >> last;
        if(first[0] == 'A' && last[0] == 'B') {
            match.push(new std::string (student));
            //match.push(&student);
        }
    }
    return match;
}


int main() {
    // Your code goes here. Don't forget to print your true love!
    std::string PATH = "students.txt";
    std::set<std::string> applicants = get_applicants(PATH);
    // for(auto elem : applicants) {
    //     std:: cout << elem << std::endl;
    // }
    auto match = find_matches(applicants);
    if(match.empty()) {
        std::cout << "NO STUDENT FOUND :(" << std::endl;
    }
    while(!match.empty()) {
        std::cout << *match.front() << std::endl;
        match.pop();
    }
    
    return 0;
}
