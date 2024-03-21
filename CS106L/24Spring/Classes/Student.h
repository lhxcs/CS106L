#include <string>

class Student {
private:
  using String = std::string;
  String name;
  String state;
  int age;

public:
  /// default constructor
  Student();

  /// constructor for our student
  Student(String name, String state, int age);

  /// Destructor
  ~Student();

  /// method to get name, state, and age, respectively
  String getName();
  String getState();
  int getAge();

  void setName(std::string name);
  void setState(std::string state);
  void setAge(int age);
};
