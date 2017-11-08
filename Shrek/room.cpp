#include "room.h"

Room::Room(QString inDescription,QString imageLocation) {
    description = inDescription;
    imageLoc = imageLocation;
}

QString Room::Description() {
    return description;
}

QString Room::getImageLoc() {
    return imageLoc;
}

