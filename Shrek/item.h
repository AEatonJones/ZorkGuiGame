#ifndef ITEM_H_
#define ITEM_H_

#include <string>
#include <iostream>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include <QGraphicsSceneMouseEvent>

class item {
protected:
    QString description;
    int xLoc;
    int yLoc;
    QString imageLoc;
    bool found;

public:
    QString getDescription();
    item (QString description, int x, int y, QString imageLoc);
    void isFound();
    int getX();
    int getY();
    QString getImageLoc();
};

#endif /*ITEM_H_*/
