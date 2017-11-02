#ifndef ITEMKEY_H
#define ITEMKEY_H

#include <QGraphicsPixMapItem>
#include <QGraphicsItem>

class ItemKey: public QGraphicsPixmapItem {

public:
    ItemKey(QGraphicsItem * child=0);
};

#endif // ITEMKEY_H
