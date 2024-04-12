#include "user.h"
#include <set>
#include <iostream>
#include <string>

User::User() {
    this->name = "";
}

User::User(std::string name) {
// TODO: Implement the additional constructor here!
    this->name = name;
}

User::User(const User &otherUser) {
    this->name = otherUser.getName();
    this->friends = otherUser.getFriends();
}


User & User::operator=(const User &rhs) {
    if(this == &rhs) {
        return *this;
    }
    this->name = rhs.getName();
    this->friends = rhs.getFriends();
    return *this;
}

User::User(User &&otherUser) {
    this->name = std::move(otherUser.getName());
    this->friends = std::move(otherUser.getFriends());
}

User & User::operator=(User &&otherUser) {
    if(this == &otherUser) {
        return *this;
    }
    this->name = std::move(otherUser.getName());
    this->friends = std::move(otherUser.getFriends());
    return *this;
}


std::string User::getName() const {
    return name;
}

std::set<User> User::getFriends() const {
    return friends;
}

void User::setName(std::string name) {
    this->name = name;
}

// TODO: Implement the < operator overload here!
bool User::operator<(const User &rhs) const {
    return this->name < rhs.name;
}