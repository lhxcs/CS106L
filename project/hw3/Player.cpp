#include "Player.h"
#include <iostream>
#include <string>
using namespace std;
extern int x, y;

int Player::getPositionX() {
    return PositionX;
}
int Player::getPositionY() {
    return PositionY;
}

void Player::SetPosition(int x, int y) {
    this->PositionX = x;
    this->PositionY = y;
}

// Move the player in the specified direction (e.g., "south", "north", "west", "east")
// Returns true if the move was successful, false otherwise
bool Player::Move(string direction) {
    while(1) {
        if(direction == "south") {
            PositionX--;
            break;
        } else if(direction == "north") {
            PositionX++;
            break;
        } else if(direction == "west") {
            PositionY--;
            break;
        } else if(direction == "east") {
            PositionY++;
            break;
        } else {
            cout << "Invalid direction. Please enter again." << endl;
            cout << "Enter your command: ";
            cin >> direction;
            cin >> direction;
        }
    }
    // Check if the player is out of bounds and adjust the position accordingly
    if(PositionX < 0) {
        cout << "No exit!" << endl;
        PositionX++;
        return false;
    } 
    if(PositionY > x - 1) {
        cout << "No exit!" << endl;
        PositionY--;
        return false;
    }
    if(PositionY < 0) {
        cout << "No exit!" << endl;
        PositionY++;
        return false;
    }
    if(PositionX > y - 1) {
        cout << "No exit!" << endl;
        PositionX--;
        return false;
    }
    return true;
}