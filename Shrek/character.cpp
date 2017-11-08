#include "character.h"
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
        if (pos().x() > -20)
            setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        setPixmap(QPixmap(":/images/character2.png"));
        if (pos().x() + 70 < 600)
            setPos(x()+10,y());
    }
    else if (event->key() == Qt::Key_Up){
        if (pos().y() > 250)
            setPos(x(),y()-10);
    }
    else if (event->key() == Qt::Key_Down){
        if (pos().y() + 80 < 378)
            setPos(x(),y()+10);
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

bool Character::foundKids() {
    bool result = false;
    if(foundFarkle) {
        if(foundFergus) {
            if(foundFelicia) {
                result = true;
            }
        }
    }
    return result;
}






