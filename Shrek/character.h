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
    bool getFoundFarkle();
    void setFoundFarkle();
    bool getFoundFergus();
    void setFoundFergus();
    bool getFoundFelicia();
    void setFoundFelicia();
    bool getHasDoll();
    void setHasDoll();
    bool getHasAxe();
    void setHasAxe();
    bool getHasKey();
    void setHasKey();
    bool foundKids();

private:
    bool foundFarkle;
    bool foundFergus;
    bool foundFelicia;
    bool hasDoll;
    bool hasAxe;
    bool hasKey;

};

#endif // CHARACTER_H
