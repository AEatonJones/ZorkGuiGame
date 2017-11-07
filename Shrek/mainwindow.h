#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QtCore>
#include <QtGui>
#include <QGraphicsPixMapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QKeyEvent>
#include "character.h"
#include "item.h"
#include "room.h"
#include <QMediaPlayer>

namespace Ui {
class MainWindow;
extern MainWindow * game;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void initilizeScreen();
    void initilizeCharacter();
    void startMusic();
    void createRooms();
    void displayMap();
    void displayJournal();
    void setRoom();
    // attributes public as they need to be accessed by other classes
    QGraphicsScene * scene;
    Character *character;
    Room *currentRoom;
    QMediaPlayer * music;
    int fps;

public slots:
    void replayMusic(QMediaPlayer::State s);


private slots:
    void on_Quit_pressed();

    void on_Journal_pressed();

    void on_Map_pressed();

private:
    Ui::MainWindow *ui;    
    //QTimer *timer;
};

#endif // MAINWINDOW_H
