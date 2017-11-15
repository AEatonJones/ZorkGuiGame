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

//Delete ui method.
MainWindow::~MainWindow() {
    delete ui;
}

//Initializes our ui and graphics scene.
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

//Initilizes our ui and graphics scene.
void MainWindow::setRoom() {
    QString backImage = currentRoom->getImageLoc();
    scene->setBackgroundBrush(QBrush(QImage(backImage)));
    ui->roomLoc->setText(currentRoom->Description());
}

//Initilizes our character and adds him to the graphics scene.
void MainWindow::initilizeCharacter()  {
    character = new Character();
    character->setPos(370,280);
    character->setFlag(QGraphicsItem::ItemIsFocusable);
    character->setFocus();
    scene->addItem(character);
    scene->setSceneRect(0,0,600,378);
    ui->graphicsView->setScene(scene);
}

/*Creates mediaplayer object and links it to a sound file.
 * It then sets the volume of the object and set it playing.
 * It connects this to a slot which check when the music file has finished.
 * When it finished it sends it to the replaymusic slot.
 * set the 2 bools to be false for the other buttons.
 */
void MainWindow::startMusic()  {
    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/music/music.mp3"));
    music->setVolume(40);
    music->play();
    connect(music,SIGNAL(stateChanged(QMediaPlayer::State)),SLOT(replayMusic(QMediaPlayer::State)));
    donkeySoundPlaying = false;
    pussSoundPlaying =false;
}

// Takes in a signal when the music has entered the stopped state, and then starts it again.
void MainWindow::replayMusic(QMediaPlayer::State s){
    if (s == QMediaPlayer::StoppedState){
        music->play();
    }
}

//Initilizes the room object the player is in.
void MainWindow::createRoom() {
    Room *shrekhouse;
    shrekhouse = new Room(tr("Garden"),tr(":/images/house1.jpg"));
    currentRoom = shrekhouse;
}

//Exits the application.
void MainWindow::on_Quit_pressed() {
    exit(0);
}

//Enters displayJournal method.
void MainWindow::on_Journal_pressed() {
    displayJournal();
}

//Gets the results of the bools inside the character object and then displays them on the qlabel.
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

//Displays message in qlabel telling the player they have won.
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
    if((!(donkeySoundPlaying)) && (!(pussSoundPlaying))) {
        donkeySoundPlaying = true;
        QMediaPlayer * donkey = new QMediaPlayer();
        donkey->setMedia(QUrl("qrc:/music/donkey.mp3"));
        donkey->setVolume(100);
        donkey->play();
        connect(donkey,SIGNAL(stateChanged(QMediaPlayer::State)),SLOT(restartDonkeyButton(QMediaPlayer::State)));
    }
}

void MainWindow::restartDonkeyButton(QMediaPlayer::State s){
    if (s == QMediaPlayer::StoppedState){
        donkeySoundPlaying = false;
    }
}

void MainWindow::on_pussBTN_pressed()
{
    if((!(donkeySoundPlaying)) && (!(pussSoundPlaying))) {
        pussSoundPlaying = true;
        QMediaPlayer * puss = new QMediaPlayer();
        puss->setMedia(QUrl("qrc:/music/pussinboots.mp3"));
        puss->setVolume(100);
        puss->play();
        connect(puss,SIGNAL(stateChanged(QMediaPlayer::State)),SLOT(restartPussButton(QMediaPlayer::State)));
    }
}

void MainWindow::restartPussButton(QMediaPlayer::State s){
    if (s == QMediaPlayer::StoppedState){
        pussSoundPlaying = false;
    }
}
