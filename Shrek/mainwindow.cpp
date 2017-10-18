#include <QGraphicsScene>
#include <QtWidgets>
#include <QImage>
#include <QKeyEvent>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "zorkul.h"
#include <QMediaPlayer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);

    character = new Character();
    //QGraphicsPixmapItem *character=new QGraphicsPixmapItem(QPixmap(":/images/character1.png"));

    character->setPos(-100,-100);
    //QGraphicsItem *character = scene->itemAt(50, 50);

    character->setFlag(QGraphicsItem::ItemIsFocusable);
    character->setFocus();

    scene->addItem(character);
    ui->graphicsView->setScene(scene);

    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    scene->setSceneRect(-200,-200,300,300);

    QPen mypen = QPen(Qt::red);

    QLineF TopLine(scene->sceneRect().topLeft(), scene->sceneRect().topRight());
    QLineF LeftLine(scene->sceneRect().topLeft(), scene->sceneRect().bottomLeft());
    QLineF RightLine(scene->sceneRect().topRight(), scene->sceneRect().bottomRight());
    QLineF BottomLine(scene->sceneRect().bottomLeft(), scene->sceneRect().bottomRight());

    scene->addLine(TopLine,mypen);
    scene->addLine(LeftLine,mypen);
    scene->addLine(RightLine,mypen);
    scene->addLine(BottomLine,mypen);

    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/music/music.mp3"));
    music->play();

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

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), scene,SLOT(advance()));
    timer->start(100);*/
}

/*MainWindow::Character(QGraphicsItem *parent): QGraphicsPixmapItem(parent) {
    setPixmap(QPixmap(":/images/character1.png"));
}*/



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
