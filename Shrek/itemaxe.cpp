#include "itemaxe.h"
//#include "MainWindow.h"
//#include <QGraphicsScene>
//#include <QPixmap>

ItemAxe::ItemAxe(QGraphicsItem *child): QGraphicsPixmapItem(child){
    setPixmap(QPixmap(":images/axe.png"));
    //pm = pm.scaled(50,50);
   // setPixmap(pm);
}


/*ItemAxe::ItemAxe(QGraphicsItem *parent){
    setPixmap(QPixmap(":images/axe.png"));
    //pm = pm.scaled(50,50);
   // setPixmap(pm);
}*/
/*ItemAxe::ItemAxe(int ct) {
    QPixmap pm(":/images/axe.png");
    pm = pm.scaled(50,50);
    setPixmap(pm);
}
void ItemAxe::use(){
    if (count == 0){
        game->character->inventory->items.removeAll(this);
        game->character->inventory->shiftLeft();
        game->scene->removeItem(this);
        return;
    }
    if (count < 0){
        return;
    }

    //create an Axe
    Axe * anAxe = new Axe(game->character);

    //set it's pos and rotation
    anAxe->setPos(game->character->getOrigin());
    //anAxe->setRotation(game->character->getAngle());

    game->scene->addItem(anAxe);

    count -=1;
    game->character->inventory->updateinventory();
}*/
