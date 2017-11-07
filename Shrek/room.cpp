#include "room.h"
#include "command.h"


Room::Room(QString inDescription,QString imageLocation) {
    description = inDescription;
    imageLoc = imageLocation;
}

void Room::setExits(Room *north, Room *east, Room *south, Room *west) {
    if (north != NULL)
        exits["north"] = north;
    if (east != NULL)
        exits["east"] = east;
    if (south != NULL)
        exits["south"] = south;
    if (west != NULL)
        exits["west"] = west;
}

QString Room::Description() {
    return description;
}


QString Room::getImageLoc() {
    return imageLoc;
}

Room* Room::nextRoom(string direction) {
    map<string, Room*>::iterator next = exits.find(direction); //returns an iterator for the "pair"
    if (next == exits.end())
        return NULL; // if exits.end() was returned, there's no room in that direction.
    return next->second; // If there is a room, remove the "second" (Room*)
                // part of the "pair" (<string, Room*>) and return it.
}

void Room::addItem(item *inItem) {
    itemsInRoom.push_back(*inItem);
}

