#include "character.h"
#include <QGraphicsScene>
#include <QKeyEvent>

Character::Character(QGraphicsItem *parent): QGraphicsPixmapItem(parent) {
    setPixmap(QPixmap(":/images/character1.png"));
}

void Character::keyPressEvent(QKeyEvent *event) {

    if (event->key() == Qt::Key_Left){
        setPixmap(QPixmap(":/images/character1.png"));
        if (pos().x() > 0)
            setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        setPixmap(QPixmap(":/images/character2.png"));
        if (pos().x() + 100 < 600)
            setPos(x()+10,y());
    }
    else if (event->key() == Qt::Key_Up){
        if (pos().y() > 0)
            setPos(x(),y()-10);
    }
    else if (event->key() == Qt::Key_Down){
        if (pos().y() + 100 < 378)
            setPos(x(),y()+10);
    }
    else if(event->key() == Qt::Key_Q) {
        setPixmap(QPixmap(":/images/character1.png"));
        if (pos().x() > 0 && pos().y() > 0)
            setPos(x()-10,y()-10);
    }
    else if(event->key() == Qt::Key_E) {
        setPixmap(QPixmap(":/images/character2.png"));
        if (pos().x() + 100 < 600 && pos().y() > 0)
            setPos(x()+10,y()-10);
    }
    else if(event->key() == Qt::Key_A) {
        setPixmap(QPixmap(":/images/character1.png"));
        if (pos().y() + 100 < 378 && pos().x() > 0)
            setPos(x()-10,y()+10);
    }
    else if(event->key() == Qt::Key_D) {
        setPixmap(QPixmap(":/images/character2.png"));
        if (pos().y() + 100 < 378 && pos().x() + 100 < 600)
            setPos(x()+10,y()+10);
    }
}

/*QRectF Character::boundingRect() const
{
    return QRect(0,0,20,20);
}*/

void Character::DoCollision()
{
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
/*&&(event->key() == Qt::Key_Up))*/
/*

Characterx::Characterx(string description) {
    this->description = description;
}
void Characterx::addItem(Item &item) {
    itemsInCharacter.push_back(item);
}
void Characterx::addItem(Item *item) {
    itemsInCharacter.push_back(*item);
    delete item;
}
string Characterx::longDescription()
{
  string ret = this->description;
  ret += "\n Item list:\n";
  for (vector<Item>::iterator i = itemsInCharacter.begin(); i != itemsInCharacter.end(); i++)
    ret += "\t"+ (*i).getLongDescription() + "\n";
  return ret;
}
*/




