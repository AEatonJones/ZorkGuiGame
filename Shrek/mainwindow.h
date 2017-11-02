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
#include "itemaxe.h"

#include "item.h"
#include "itemkey.h"
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
    //void mouseMoveEvent(QMouseEvent *event);

    //void mousePressEvent(QMouseEvent *event);

    //void mouseDoubleClickEvent(QMouseEvent *event);

    //void resizeEvent(QResizeEvent *event);

    //void keyPressEvent(QKeyEvent * event);

    //void placeItem(Item *item, int x, int y);

        // attributes public as they need to be accessed by other classes
    QGraphicsScene * scene;
    Character *character;
    ItemAxe *itemaxe;
    ItemKey *itemkey;

    QMediaPlayer * music;
    int fps;

public slots:
    void replayMusic(QMediaPlayer::State s);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_pressed();

    void on_pushButton_2_clicked();

    void on_moveLeft_clicked();

    void on_moveRight_clicked();

    void on_moveUp_clicked();

    void on_moveDown_clicked();

private:
    Ui::MainWindow *ui;    
    //QTimer *timer;
};

#endif // MAINWINDOW_H
