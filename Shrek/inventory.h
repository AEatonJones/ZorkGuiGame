/*#ifndef INVENTORY_H
#define INVENTORY_H

#include <QList>
#include "item.h"
#include <QGraphicsRectItem>


class Inventory: public QGraphicsRectItem{

public:
    Inventory();
    void updateInv();

    void addItem(Item *item);

    void shiftLeft();

    //attributes
    Item * left_click_item;
    Item * right_click_item;
    Item * middle_click_item;
    QList<Item *> items;
};

#endif // INVENTORY_H*/
