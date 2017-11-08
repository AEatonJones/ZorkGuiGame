#include <QGraphicsScene>
#include <QtWidgets>
#include <QKeyEvent>
#include <QBrush>
#include <QImage>
#include <stdlib.h>
#include <QMediaPlayer>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "zorkul.h"
#include "room.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    createRoom();
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
    setWindowTitle("Shrek");
}

void MainWindow::setRoom() {
    QString backImage = currentRoom->getImageLoc();
    scene->setBackgroundBrush(QBrush(QImage(backImage)));
    ui->roomLoc->setText(currentRoom->Description());
}

void MainWindow::initilizeCharacter()  {
    character = new Character();
    character->setPos(370,280);
    character->setFlag(QGraphicsItem::ItemIsFocusable);
    character->setFocus();
    scene->addItem(character);
    scene->setSceneRect(0,0,600,378);
    ui->graphicsView->setScene(scene);
}

void MainWindow::startMusic()  {
    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/music/music.mp3"));
    music->setVolume(40);
    music->play();
    connect(music,SIGNAL(stateChanged(QMediaPlayer::State)),SLOT(replayMusic(QMediaPlayer::State)));
    donkeySoundPlaying = false;
}

void MainWindow::replayMusic(QMediaPlayer::State s){
    if (s == QMediaPlayer::StoppedState){
        music->play();
    }
}



void MainWindow::createRoom() {
    Room *shrekhouse;
    shrekhouse = new Room(tr("House"),tr(":/images/house1.jpg"));
    currentRoom = shrekhouse;
}

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
    QString journalEntry = "Journal\n-----------\nFound Farkle: " + resultFarkle + "\nFound Felicia: " + resultFelicia + ""
                           "\nFound Fergus: " + resultFergus + "\nHave Axe: " + resultAxe + "\nHave Doll: " + resultDoll + "\nHave Key: " + resultKey;
    ui->logText->setText(journalEntry);
}

void MainWindow::playerWin() {
    ui->logText->setText("YOU HAVE FOUND ALL YOUR KIDS AND WON!");
}

void MainWindow::on_fergusBTN_pressed()
{
    if(character->getHasAxe()) {
        character->setFoundFergus();
        ui->fergusBTN->setVisible(false);
        ui->logText->setText(tr("You picked up Fergus!"));
        if(character->foundKids()) {
            playerWin();
        }
    }
    else {
        ui->logText->setText(tr("I want to practice fighting so I can be a knight like you dad."));
    }
}

void MainWindow::on_farkleBTN_pressed()
{
    if(character->getHasKey()) {
        character->setFoundFarkle();
        ui->farkleBTN->setVisible(false);
        ui->logText->setText(tr("You picked up Farkle!"));
        if(character->foundKids()) {
            playerWin();
        }
    }
    else {
        ui->logText->setText(tr("I need the key to the outhouse."));
    }
}

void MainWindow::on_feliciaBTN_pressed()
{
    if(character->getHasDoll()) {
        character->setFoundFelicia();
        ui->logText->setText(tr("You picked up Felicia!"));
        ui->feliciaBTN->setVisible(false);
        if(character->foundKids()) {
            playerWin();
        }
    }
    else {
        ui->logText->setText(tr("I lost track of my doll, can you find it for me dad?"));
    }
}

void MainWindow::on_axeBTN_pressed()
{
    character->setHasAxe();
    ui->axeBTN->setVisible(false);
    ui->logText->setText(tr("You have found the axe, use it to get Fergus!"));
}

void MainWindow::on_keyBTN_pressed()
{
    character->setHasKey();
    ui->keyBTN->setVisible(false);
    ui->logText->setText(tr("You have found the key, use it to get Farkle!"));
}

void MainWindow::on_dollBTN_pressed()
{
    character->setHasDoll();
    ui->dollBTN->setVisible(false);
    ui->logText->setText(tr("You have found the doll, use it to get Felicia!!"));
}

void MainWindow::on_donkeyBTN_pressed()
{
    if(!(donkeySoundPlaying)) {
        donkeySoundPlaying = true;
        QMediaPlayer * donkey = new QMediaPlayer();
        donkey->setMedia(QUrl("qrc:/music/donkey.mp3"));
        donkey->setVolume(100);
        donkey->play();
        connect(donkey,SIGNAL(stateChanged(QMediaPlayer::State)),SLOT(restartButton(QMediaPlayer::State)));
    }
}

void MainWindow::restartButton(QMediaPlayer::State s){
    if (s == QMediaPlayer::StoppedState){
        donkeySoundPlaying = false;
    }
}
