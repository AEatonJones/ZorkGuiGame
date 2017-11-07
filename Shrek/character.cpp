//#include "mainwindow.h"
#include "character.h"
//#include "itemaxe.h"
#include <QGraphicsScene>
#include <QKeyEvent>
//#include <QDebug>

Character::Character(QGraphicsItem *parent): QGraphicsPixmapItem(parent) {
    setPixmap(QPixmap(":/images/character1.png"));
    foundFarkle = false;
    foundFergus = false;
    foundFelicia = false;
    hasAxe = false;
    hasDoll = false;
    hasKey = false;
}

void Character::keyPressEvent(QKeyEvent *event) {

    if (event->key() == Qt::Key_Left){
        setPixmap(QPixmap(":/images/character1.png"));
        if (pos().x() > 0)
            setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        setPixmap(QPixmap(":/images/character2.png"));
        if (pos().x() + 80 < 600)
            setPos(x()+10,y());
    }
    else if (event->key() == Qt::Key_Up){
        if (pos().y() > 0)
            setPos(x(),y()-10);
    }
    else if (event->key() == Qt::Key_Down){
        if (pos().y() + 80 < 378)
            setPos(x(),y()+10);
    }

    /*QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size();i<n;i++){
        if (typeid(ItemAxe) == typeid(*colliding_items[i])){
            //game->scene->removeItem(colliding_items[i]);
        }
        else{
            Item * item = dynamic_cast<Item *>(colliding_items[i]);
            //player collides with item - adds item to inventory.
            if (item != nullptr && item->picked == false){
                 inventory->addItem(item);
            }
        }
    }
    x_prev = pos().x();
    y_prev = pos().y();*/
}

/*QRectF Character::boundingRect() const
{
    return QRect(0,0,20,20);
}*/

void Character::DoCollision() {
    //see if the new position is in bounds
    QPointF newpoint = mapToParent(-(boundingRect().width()), -(boundingRect().width() + 2));

    if(!scene()->sceneRect().contains((newpoint)))
    {
        //move it back in bounds
        newpoint = mapToParent(0,0);
    }
    else
    {
        //set the new position
        setPos(newpoint);
    }
}

bool Character::getFoundFarkle() { return foundFarkle; }
bool Character::getFoundFergus() { return foundFergus; }
bool Character::getFoundFelicia() { return foundFelicia; }
bool Character::getHasAxe() { return hasAxe; }
bool Character::getHasDoll() { return hasDoll; }
bool Character::getHasKey() { return hasKey; }

void Character::setFoundFarkle() { foundFarkle = true; }
void Character::setFoundFergus() { foundFergus = true; }
void Character::setFoundFelicia() { foundFelicia = true; }
void Character::setHasAxe() { hasAxe = true; }
void Character::setHasDoll() { hasDoll = true; }
void Character::setHasKey() { hasKey = true; }






