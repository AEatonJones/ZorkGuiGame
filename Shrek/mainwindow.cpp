#include <QGraphicsScene>
#include <QLineF>
#include <QPointF>
#include <QCursor>
#include <QtWidgets>
#include <QKeyEvent>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "zorkul.h"
#include <QMediaPlayer>
#include <QBrush>
#include <QImage>
//#include "inventory.h"
#include "item.h"

#include <stdlib.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    fps = 30;
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    scene->setBackgroundBrush(QBrush(QImage(":/images/swamp1.png")));

    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff );
    setFixedSize(730,450);

    character = new Character();
    character->setPos(400,250);
    character->setFlag(QGraphicsItem::ItemIsFocusable);
    character->setFocus();

    scene->addItem(character);
    scene->setSceneRect(0,0,600,378);
    ui->graphicsView->setScene(scene);

    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/music/music.mp3"));
    music->play();
    connect(music,SIGNAL(stateChanged(QMediaPlayer::State)),SLOT(replayMusic(QMediaPlayer::State)));

    // add character's inventory to the scene
    //character->inventory = new Inventory();
    //scene->addItem(character->inventory);

    setMouseTracking(true);

    setWindowTitle("Detective Shrek");

    itemaxe = new ItemAxe();
    itemaxe->setPos(300,200);
    scene->addItem(itemaxe);

    //timer = new QTimer(this);
    //connect(timer, SIGNAL(timeout()), scene,SLOT(advance()));
    //timer->start(100);

    /*
    int ItemCount = 25;
    for(int i = 0; i < ItemCount; i++)
    {
       MyItem *item = new MyItem();
       scene->addItem(item);
    }
    */
}
/*void MainWindow::mousePressEvent(QMouseEvent *event){
    // if the left button was clicked
    if (event->button() == Qt::LeftButton){
        // inventory clicked
        if (character->inventory->contains(event->pos())){
            QMainWindow::mousePressEvent(event);
            return;
        }
        // if there is nothing mapped to this click, return (do nothing)
        if (character->inventory->left_click_item == nullptr){
            return;
        }
        //if an item is mapped to left click - use item
        character->inventory->left_click_item->use();
    }

    // right button clicked
    if (event->button() == Qt::RightButton){
        if (character->inventory->contains(event->pos())){
            QMainWindow::mousePressEvent(event);
            return;
        }
        if (character->inventory->right_click_item == nullptr){
            return;
        }
        character->inventory->right_click_item->use();
    }

    // middle button clicked
    if (event->button() == Qt::MiddleButton){
        if (character->inventory->contains(event->pos())){
            QMainWindow::mousePressEvent(event);
            return;
        }

        if (character->inventory->middle_click_item == nullptr){
            return;
        }
        character->inventory->middle_click_item->use();
    }
}*/

/*void MainWindow::placeItem(Item * item, int x, int y){
    // places the item at the specified location on the scene
    scene->addItem(item);
    item->setPos(x,y);
}*/

void MainWindow::replayMusic(QMediaPlayer::State s){
    if (s == QMediaPlayer::StoppedState){
        music->play();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->label->setText("Oh no, it's Shrek!");
}

void MainWindow::on_pushButton_pressed()
{
    ui->label->setText("Oh no, it's Shrek!");
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->textBrowser->setText("Oh no, it's Shrek again!");
}

void MainWindow::on_moveLeft_clicked()
{
    //setPixmap(QPixmap(":/images/character1.png"));
    //setPos(x()-10,y());
}

void MainWindow::on_moveRight_clicked()
{
    //setPixmap(QPixmap(":/images/character2.png"));
    //setPos(x()+10,y());
}

void MainWindow::on_moveUp_clicked()
{
    //setPixmap(QPixmap(":/images/character1.png"));
    //setPos(x(),y()-10);
}

void MainWindow::on_moveDown_clicked()
{
    //setPixmap(QPixmap(":/images/character1.png"));
    //setPos(x(),y()+10);
}
