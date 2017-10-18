#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QtCore>
#include <QtGui>
#include "character.h"
#include <QGraphicsPixMapItem>
#include <QObject>
#include <QGraphicsItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

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
    QGraphicsScene *scene;
    Character *character;
    //QTimer *timer;
};

#endif // MAINWINDOW_H
