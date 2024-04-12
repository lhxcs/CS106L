#include <set>
#include <string>

class User {
public:
    // TODO: write special member functions, including default constructor!
    User();
    User(const User &otherUser); // 拷贝构造函数，用于创建一个新对象并将其初始化另一个对象 otherUser 的副本
    User& operator=(const User &otherUser); // 拷贝赋值运算符重载函数
    User(User &&rhs); // 移动构造函数
    User & operator=(User &&otherUser);

    

    User(std::string name);

    // getter functions
    std::string getName() const;
    std::set<User> getFriends() const;

    // setter functions
    void setName(std::string name);
    friend User && operator+(User &&lhs, const User &rhs);

    // TODO: add the < operator overload here!
    bool operator<(const User &rhs) const;

    
private:
    std::string name;
    std::set<User> friends;

};