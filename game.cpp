#include "game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "enemies.h"
#include <QWidget>
#include <QGraphicsScene>
#include "actor.h"
#include "score.h"
#include "health.h"
#include <QTimer>
#include <QMediaPlayer>
#include <QGraphicsTextItem>



Game::Game(QWidget *parent):QGraphicsView(parent){
    // create the scene
    scene = new QGraphicsScene();
    setAttribute(Qt::WA_DeleteOnClose);
    scene->setSceneRect(0,0,800,600); // make the scene 800x600 instead of infinity by infinity (default)

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    // create the player
    player = new Actor();
    player->setPixmap(QPixmap(":/images/player2.jpg"));// change the rect from 0x0 (default) to 100x100 pixels
    player->setPos(400,500);
    // make the player focusable and set it to be the current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // add the player to the scene
    scene->addItem(player);

    // create the score/health
    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);
    QObject::connect(health,SIGNAL(die()),SLOT(gameOver()));


    // spawn enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);

    //background sound
    music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/bg1.mp3"));
    music->play();
    show();


}
void Game::gameOver()
{
    scene->clear();
    music->stop();
    QString message;
    message=" GGGame Over ";
    displayGameOverWindow(message);
}
void Game::displayGameOverWindow(QString textToDisplay){
    // disable all scene items
    for (size_t i = 0, n = scene->items().size(); i < n; i++){
        scene->items()[i]->setEnabled(false);
    }

    // pop up semi transparent panel
    drawPanel(0,0,800,600,Qt::black,0.5);

    // draw panel
    drawPanel(200,100,400,400,Qt::lightGray,0.75);



    // create quit button
    Button* quit = new Button(QString("Quit"));
    quit->setPos(300,300);
    scene->addItem(quit);
    QObject::connect(quit,SIGNAL(clicked()),this,SLOT(close()));

    // create text annoucning winner
    QGraphicsTextItem* overText = new QGraphicsTextItem(textToDisplay);
    overText->setPos(250,150);
    overText->setFont(QFont("times",32));
    scene->addItem(overText);

}

void Game::drawPanel(int x, int y, int width, int height, QColor color, double opacity){
    // draws a panel at the specified location with the specified properties
    QGraphicsRectItem* panel = new QGraphicsRectItem(x,y,width,height);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    panel->setBrush(brush);
    panel->setOpacity(opacity);
    scene->addItem(panel);
}

