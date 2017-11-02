#include "itemkey.h"

ItemKey::ItemKey(QGraphicsItem *child): QGraphicsPixmapItem(child){
    setPixmap(QPixmap(":images/key.png"));
}

