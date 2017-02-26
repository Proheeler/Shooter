#include "health.h"
#include "game.h"
extern Game *game;

Health::Health(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
//initialize the score
    health =1;
//set score on screen
    setPlainText(QString("Health: ")+QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Health::decrease()
{
    if (--health<0)
    {
        emit die();

    }
    else setPlainText(QString("Health: ")+QString::number(health));

}

int Health::getHealth()
{
    return health;
}


