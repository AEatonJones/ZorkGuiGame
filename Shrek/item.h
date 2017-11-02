#ifndef ITEM_H_
#define ITEM_H_

//#include <map>
//#include <string>
//#include <iostream>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include <QGraphicsSceneMouseEvent>

using namespace std;

class Item {
private:
    /*string description;
    string longDescription;
    int weightGrams;
    float value;*/

public:
    Item(int ct);

    virtual void use();
    virtual int getCount();
    virtual void setCount(int c);
    virtual void setAsLeftClickItem();
    virtual void setAsRightClickItem();
    virtual void setAsMiddleClickItem();
    virtual void mousePressEvent(QGraphicsSceneMouseEvent * event);

    bool picked;
    QGraphicsTextItem * count_text;
    int count;
    int index;
};

#endif /*ITEM_H_*/
