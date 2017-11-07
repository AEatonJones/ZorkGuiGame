#ifndef ROOM_H_
#define ROOM_H_

#include <map>
#include <string>
#include <vector>
#include "item.h"
using namespace std;
using std::vector;

class Room {

private:
    QString description;
    QString imageLoc;
    map<string, Room*> exits;
    vector <item> itemsInRoom;


public:
    Room(QString description,QString imageLoc);
    void setExits(Room *north, Room *east, Room *south, Room *west);
    QString Description();
    QString getImageLoc();
    Room* nextRoom(string direction);
    void addItem(item *inItem);
};

#endif
