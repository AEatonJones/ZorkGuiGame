#include "mainwindow.h"
#include "item.h"

item::item (QString inDescription, int x, int y, QString imageLocation) {
    description = inDescription;
    xLoc = x;
    yLoc = y;
    imageLoc = imageLocation;
}

int item::getX() {
    return xLoc;
}

int item::getY() {
    return yLoc;
}

QString item::getImageLoc() {
    return imageLoc;
}

void item::isFound() {
    found = true;
}

QString item::getDescription() {
    return description;
}




