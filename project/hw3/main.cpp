#include <iostream>
#include "Room.h"
#include "Player.h"
#include "Game.h"
using namespace std;
int x, y;

int main() {
    cout << "Haha! Welcome to the adventure!" <<endl;
    cout << "You are in a castle now. You need to find the princess and save her!" << endl;
    cout << "But be careful! There is a monster in the castle!" << endl;
    cout << "You can move to the north, south, east, or west." << endl;
    cout << "You can only move to the next room." << endl;
    cout << "The map is a x * y matrix.(x * y must be greater than 3!)" << endl;
    cout << "Now choose your map size!" << endl;
    cout << "Please enter the size of the map(format: x y): " << endl;
    cin >> x >> y;
    while(1) {
        // Validate the map size
        if(x * y < 3) {
            cout << "Invalid Input!" << endl;
            cout << "Please enter the size of the map(format: x y): " << endl;
            cin >> x >> y;
        } else {
            // Start the game
            cout << "Now begin your adventure! GOOD LUCK!!!!"<<endl;
            Game game(x, y);
            game.Start();
            return 0;
        }
    }
}