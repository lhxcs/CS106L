#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string>

class Player {
public:
    int getPositionX(); // Get the x-coordinate of the player
    int getPositionY(); // Get the y-coordinate of the player
    void SetPosition(int x, int y); // Set the position of the player
    bool Move(std::string direction); //Move the player in the specified direction, return true if the move is valid, false otherwise
private:
    int PositionX; 
    int PositionY;
};
#endif