#include "Room.h"
#include <iostream>
using namespace std;

void Room::CreateRoom(int type) {
    roomType = type;
}

void Room::resetVisited() {
    isVisited = false;
}

void Room::setVisited() {
    isVisited = true;
}

void Room::PrintRoom() {
    if(isVisited) { //If visited, Print different symbols based on the room type
        if(roomType == 0) {
            cout << "[         ]";
        } else if(roomType == 1) {
            cout << "[  Lobby  ]";
        } else if(roomType == 2) {
            cout << "[ Monster ]";
        } else if(roomType == 3) {
            cout << "[Princess!]";
        }
    }else {  // Room not visited yet
        cout << "[    ?    ]";
    }
}