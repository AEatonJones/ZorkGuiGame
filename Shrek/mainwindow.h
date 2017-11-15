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
#include <QKeyEvent>
#include <QMediaPlayer>
#include "character.h"
#include "room.h"

namespace Ui {
class MainWindow;
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
    void createRoom();
    void displayJournal();
    void setRoom();
    void playerWin();

    // attributes public as they need to be accessed by other classes
    QGraphicsScene * scene;
    Character *character;
    Room *currentRoom;
    QMediaPlayer * music;
    int fps;
    bool donkeySoundPlaying;
    bool pussSoundPlaying;

public slots:
    void replayMusic(QMediaPlayer::State s);
    void restartDonkeyButton(QMediaPlayer::State s);
    void restartPussButton(QMediaPlayer::State s);

private slots:
    void on_Quit_pressed();

    void on_Journal_pressed();

    void on_fergusBTN_pressed();

    void on_farkleBTN_pressed();

    void on_feliciaBTN_pressed();

    void on_axeBTN_pressed();

    void on_keyBTN_pressed();

    void on_dollBTN_pressed();

    void on_donkeyBTN_pressed();

    void on_pussBTN_pressed();

private:
    Ui::MainWindow *ui;    
};

#endif // MAINWINDOW_H
