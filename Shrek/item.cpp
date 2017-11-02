#include "mainwindow.h"
#include "item.h"
#include <QPixmap>

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QBrush>
#include <QRect>
#include <QDebug>
#include <QFont>

Item::Item(int ct){
    // set attributes
    count = ct;
    picked = false;

    //set count text
    //count_text = new QGraphicsTextItem(QString::number(count),this);
    //count_text->setFont(QFont("Times New Roman",12));
    //count_text->setDefaultTextColor(Qt::red);
}

void Item::use(){
}

int Item::getCount(){
    return count;
}

void Item::setCount(int c){
    count = c;
}

void Item::setAsLeftClickItem(){
    //game->character->inventory->left_click_item = this;
}

void Item::setAsRightClickItem(){
    //game->character->inventory->right_click_item = this;
}

void Item::setAsMiddleClickItem(){
    //game->character->inventory->middle_click_item = this;
}

void Item::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if (event->button() == Qt::LeftButton){
        setAsLeftClickItem();
        //game->scene->setFocusItem(game->character);
    }

    if (event->button() == Qt::RightButton){
        setAsRightClickItem();
        //game->scene->setFocusItem(game->character);
    }

    if (event->button() == Qt::MiddleButton){
        setAsMiddleClickItem();
        //game->scene->setFocusItem(game->character);
    }
}

/*Item::Item (string inDescription, float inventoryalue) {
    description = inDescription;    
    value = inventoryalue;
}

Item::Item(string inDescription) {
    description = inDescription;
}

void Item::setValue(float inventoryalue)
{
    if (inventoryalue > 9999 || inventoryalue < 0)
       cout << "value inventoryalid, must be 0<value<9999" ;
    else
       value = inventoryalue;
}

string Item::getShortDescription()
{
    return description;
}

string Item::getLongDescription()
{
    return " item(s), " + description + ".\n";
}*/


