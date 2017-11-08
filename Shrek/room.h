#ifndef ROOM_H_
#define ROOM_H_

#include <map>
#include <string>
#include <vector>
#include <QString>
using namespace std;

class Room {

private:
    QString description;
    QString imageLoc;


public:
    Room(QString description,QString imageLoc);
    QString Description();
    QString getImageLoc();
};

#endif
