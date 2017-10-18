#ifndef ZORKUL_H_
#define ZORKUL_H_

#include "command.h"
#include "parser.h"
#include "room.h"
#include "item.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ZorkUL {
private:
    Parser parser;
    Room *currentRoom;
    void createRooms();
        vector <Room*> ListRooms;
    void printWelcome();
        void teleport();
    bool processCommand(Command command);
    void printHelp();
    void goRoom(Command command);
    void createItems();
    void displayItems();

public:
    ZorkUL();
    void play();
    string go(string direction);
};

#endif /*ZORKUL_H_*/
