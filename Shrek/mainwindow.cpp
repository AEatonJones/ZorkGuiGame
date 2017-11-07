#include <QGraphicsScene>
#include <QLineF>
#include <QPointF>
#include <QCursor>
#include <QtWidgets>
#include <QKeyEvent>
#include <QBrush>
#include <QImage>
#include <stdlib.h>
#include <QMediaPlayer>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "zorkul.h"
#include "item.h"
#include "room.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    createRooms();
    initilizeScreen();
    initilizeCharacter();
    startMusic();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::initilizeScreen()  {
    fps = 30;
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    setRoom();
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff );
    setFixedSize(850,450);
    setMouseTracking(true);
    setWindowTitle("Detective Shrek");
}

void MainWindow::setRoom() {
    QString backImage = currentRoom->getImageLoc();
    scene->setBackgroundBrush(QBrush(QImage(backImage)));
    ui->roomLoc->setText(currentRoom->Description());
}

void MainWindow::initilizeCharacter()  {
    character = new Character();
    character->setPos(400,250);
    character->setFlag(QGraphicsItem::ItemIsFocusable);
    character->setFocus();
    scene->addItem(character);
    scene->setSceneRect(0,0,600,378);
    ui->graphicsView->setScene(scene);
}

void MainWindow::startMusic()  {
    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/music/music.mp3"));
    music->play();
    connect(music,SIGNAL(stateChanged(QMediaPlayer::State)),SLOT(replayMusic(QMediaPlayer::State)));
}

void MainWindow::replayMusic(QMediaPlayer::State s){
    if (s == QMediaPlayer::StoppedState){
        music->play();
    }
}


void MainWindow::createRooms() {
 Room *a, *b, *c, *d, *e, *f, *g, *h;
        a = new Room(tr("House"),tr(":/images/house.png"));
          // a->addItem("Farkle", 8, 4);
          // a->addItem("Fergus", 8, 4);
          // a->addItem("Felicia", 8, 4);
        b = new Room(tr("Garden"),tr(":/images/garden.png"));
        c = new Room("Bath Area",tr(":/images/batharea.png"));
        d = new Room("Outhouse",tr(":/images/outhouse.png"));
        e = new Room("Forest1",tr(":/images/forest1.png"));
        f = new Room("Forest2",tr(":/images/forest2.png"));
        g = new Room("Cross-Roads",tr(":/images/crossroads.png"));
        h = new Room("Ruined House",tr(":/images/ruinedhouse.png"));

    //         (N, E, S, W)
    a->setExits(NULL, NULL, b, NULL);
    b->setExits(a, c, g, e);
    c->setExits(d, NULL, NULL, b);
    d->setExits(NULL,NULL, c, NULL);
    e->setExits(NULL, b, f, NULL);
    f->setExits(e, g, NULL, NULL);
    g->setExits(b, h, NULL, f);
    h->setExits(NULL, NULL, NULL, g);
    currentRoom = a;

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

void MainWindow::on_Quit_pressed() {
    exit(0);
}

void MainWindow::on_Journal_pressed() {
    displayJournal();
}

void MainWindow::displayJournal() {
    QString resultFarkle = QString::number(character->getFoundFarkle());
    QString resultFelicia = QString::number(character->getFoundFelicia());
    QString resultFergus = QString::number(character->getFoundFergus());
    QString resultAxe =  QString::number(character->getHasAxe());
    QString resultDoll = QString::number(character->getHasDoll());
    QString resultKey = QString::number(character->getHasKey());
    QString journalEntry = "\nJournal\n-----------\nFound Farkle: " + resultFarkle + "\nFound Felicia: " + resultFelicia + ""
                           "\nFound Fergus: " + resultFergus + "\nHave Axe: " + resultAxe + "\nHave Doll: " + resultDoll + "\nHave Key: " + resultKey;
    ui->logText->setText(journalEntry);

}

void MainWindow::on_Map_pressed() {
    displayMap();
}

void MainWindow::displayMap() {
    ui->logText->setText(tr("\n                       [oh]\n                         |\n                         |\n[f1] --- [hh] --- [ba]\n |             |\n"
                            " |             |\n[f2] --- [cr] --- [rh]"));
}
