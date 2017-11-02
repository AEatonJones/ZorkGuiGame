#ifndef CHARACTER_H
#define CHARACTER_H

#include <QGraphicsPixMapItem>
#include <QObject>
#include <QKeyEvent>
#include <QGraphicsItem>

class Character:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Character(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);
private:
    void DoCollision();
};

#endif // CHARACTER_H
