#include "Game.h"
#include "Room.h"
#include "Player.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int monsterX, monsterY;
int princessX, princessY;

Game::Game(int x, int y) : x(x), y(y) {  
    srand(time(0));// Seed the random number generator
    for(int i = 0; i < y; i++) {
        for(int j = 0; j < x; j++) {
            Castle[i][j].resetVisited();
        }
    }
    
    // Generate random positions for the monster and princess
    // Ensure that they are not placed in the lobby or on top of each other
    while (1) {
        monsterX = rand() % y;
        monsterY = rand() % x;
        if (!(monsterX == 0 && monsterY == x / 2)) {
            break;
        }
    }
   
    while (1) {
        princessX = rand() % y;
        princessY = rand() % x;
        if (!(princessX == 0 && princessY == x / 2) && !(princessX == monsterX && princessY == monsterY)) {
            break;
        }
    }

    // Initialize the castle layout with rooms and set the player's initial position
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            if (i == 0 && j == x / 2) {
                Castle[i][j].CreateRoom(1); // Lobby room
                Castle[i][j].setVisited();
            }
            if (i == monsterX && j == monsterY) {
                Castle[i][j].CreateRoom(2); // Monster room
            }
            if (i == princessX && j == princessY) {
                Castle[i][j].CreateRoom(3); // Princess room
            }
        }
    }
    // Set the player's initial position to the lobby
    player.SetPosition(0, x / 2);
}

void Game::Start() {
    PrintGameStatus();
    cout << "Welcome to the Lobby!" << endl;
    PrintHint(0, x / 2);
    bool isFind = false;  // Flag to track if the princess has been found
    
    // Main game loop
    while (1) {
        if (!GetCommand()) { // Get player command and process it
            cout << "Invalid direction. Please enter again." << endl;
            continue;
        }
        // Print the updated game status
        PrintGameStatus();

        // Check for game over conditions and provide appropriate messages
        if (player.getPositionX() == princessX && player.getPositionY() == princessY) {
            if(!isFind) {
                cout << "Princess: Oh!!! You are here! I am waiting for you!" << endl;
                cout << "Princess: Please bring me to the lobby!" << endl;
                cout << "You: Sure! I will protect you!" << endl;
                cout << "Now you need to bring the princess to the lobby! Be aware of the monster!!" << endl;
                isFind = true;
            } else {
                cout << "You and the princess come back to the prison, please bring her to the lobby!" << endl;
            }
        }
        else if (player.getPositionX() == monsterX && player.getPositionY() == monsterY) {
            cout << "Oh no!! The monster has eaten you!" << endl;
            cout << "Game Over!" << endl;
            break;
        }
        else if (player.getPositionX() == 0 && player.getPositionY() == x / 2) {
            if (isFind) {
                cout << "Yeah! You have saved the princess successfully!" << endl;
                cout << "Congratulations! You win!" << endl;
                break;
            }
        } else {
            cout << "You are in an empty cell." << endl;
        }
        PrintHint(player.getPositionX(), player.getPositionY());
    }
}

// Print the current game status (castle layout and player position)
void Game::PrintGameStatus() {
    for (int i = y - 1; i >= 0; i--) {
        for (int j = 0; j < x; j++) {
            Castle[i][j].PrintRoom();
            if (i == player.getPositionX() && j == player.getPositionY()) {
                cout << "<--P "; // Print player marker
            } else {
                cout << "     ";
            }
        }
        cout << endl;
    }
}

// Print possible exits for the player based on their position
void Game::PrintHint(int px, int py) {
    if(x > 1 && y > 1) {
        if(px == y - 1 && py == x - 1) {
            cout << "There are 2 exits: west and south. Enter your command: ";
        } else if(px == y - 1 && py == 0) {
            cout << "There are 2 exits: east and south. Enter your command: ";
        } else if(px == x - 1) {
            cout << "There are 3 exits: east, west and south. Enter your command: ";
        } else if(px == 0 && py == x - 1) {
            cout << "There are 2 exits: west and north. Enter your command: ";
        } else if(px == 0 && py == 0) {
            cout << "There are 2 exits: east and north. Enter your command: ";
        } else if(px == 0) {
            cout << "There are 3 exits: west, east and north. Enter your command: ";
        } else if(py == 0) {
            cout << "There are 3 exits: east, south and north. Enter your command: ";
        } else if(py == x - 1) {
            cout << "There are 3 exits: west, south and north. Enter your command: ";
        } else {
            cout << "There are 4 exits: east, west, south and north. Enter your command: ";
        }
    } else if(x == 1) {
        if(px == 0) {
            cout << "There is 1 exit: north. Enter your command: ";
        } else if(px == y - 1) {
            cout << "There is 1 exit: south. Enter your command: ";
        } else {
            cout << "There are 2 exits: south and north. Enter your command: ";
        }
    } else {
        if(py == 0) {
            cout << "There is 1 exit: east. Enter your command: ";
        } else if(py == x - 1) {
            cout << "There is 1 exit: west. Enter your command: ";
        } else {
            cout << "There are 2 exits: east and west. Enter your command: ";
        }
    }
}

// Get the player's command and move the player
bool Game::GetCommand() {
    string command;
    cin >> command;
    cin >> command;
    if (player.Move(command)) {
        Castle[player.getPositionX()][player.getPositionY()].setVisited();
        return true;
    } else {
        return false;
    }
}
