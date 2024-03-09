#include<iostream>
#include<sstream>

using std::cout,std::cin, std::endl, std::flush, std::string;
using std::ostringstream, std::istringstream;
using std::istream, std::ostream;
using std::stringstream;

int stringToInteger(const string& s);

int main() {
    string str = "Hello world!";
    cout << str[1] <<endl;
    str[1] = 'i';
    cout << str <<endl;

    ostringstream oss ("Ito-En Green Tea", ostringstream::ate);
    cout << oss.str() << endl;
    oss << "16.9 Ounces";
    cout << oss.str() << endl;

    istringstream iss("16.9 Ounces");

    int amount;
    string unit;
    iss >> amount;
    iss >> unit;

    cout << amount/2 <<endl;
    cout << unit <<endl;

    string name, response;
    int age;

    cout << "What is your name?";
    //cin >> name;
    getline(cin, name);
    cout << name << endl;


    return 0;
}


/*In-class practice*/
int stringToInteger(const string& s) {
    istringstream iss(s);
    int result;
    iss >> result;
    return result;
}

