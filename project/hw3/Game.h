#ifndef GAME_H
#define GAME_H
#define MAXSIZE 100

#include "Room.h"
#include "Player.h"

class Game {
private:
    Room Castle[MAXSIZE][MAXSIZE]; // 2D array to represent the castle layout
    Player player; // Player object to represent the player in the game
    int x, y;

public:
    Game(int x, int y); // Constructor to initialize the game with a given size
    void Start(); // Start the game
    void PrintGameStatus(); // Print the current game status (castle layout and player position)
    void PrintHint(int px, int py);
    bool GetCommand();
};

#endif
