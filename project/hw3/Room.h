#ifndef _ROOM_H_
#define _ROOM_H_

// Room class definition
class Room {
public:
    void CreateRoom(int type); // Create a room with a specific type(0: normal room, 1: lobby, 2: monster, 3: princess)
    void PrintRoom(); // Print the room
    void setVisited(); // Set the room as visited
    void resetVisited(); // Reset the room as not visited
private:
    int roomType = 0;
    bool isVisited = false;
};
#endif