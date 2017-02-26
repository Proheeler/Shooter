#include "enemies.h"
#include <QTimer>
#include <stdlib.h>
#include "game.h"
#include <QGraphicsScene>
extern Game *game;

Enemies::Enemies()
{
    //set random position
    int random_number=rand()%700;
    setPos(random_number,0);
    //drew the enemy
    setPixmap(QPixmap(":/images/enemy.jpg"));
    //connect
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),SLOT(move()));
    timer->start(50);
}

void Enemies::move()
{
    //move enemy down
    setPos(x(),y()+5);
    if (pos().y()>600){
        scene()->removeItem(this);
        game->health->decrease();
        delete this;
    }
}
