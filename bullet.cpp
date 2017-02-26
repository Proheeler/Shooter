#include "bullet.h"
#include <QTimer>
#include <typeinfo>
#include <enemies.h>
#include <score.h>
#include "game.h"
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QList>
extern Game *game;


Bullet::Bullet()
{
    //drew the bullet
    setPixmap(QPixmap(":/images/bullet2.jpg"));
    //connect
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),SLOT(move()));
    timer->start(50);
}

void Bullet::move()
{
    //check if bullet collides enemy
    QList<QGraphicsItem*>colliding_items=collidingItems();
    for (int i=0,n=colliding_items.size();i<n;++i)
    {
        if (typeid(*colliding_items[i])==typeid(Enemies))
        {
            //increase the score
            game->score->increase();
            //remove them both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            //deete them both
            delete colliding_items[i];
            delete this;
            return;
        }
    }
    // if there was no collision with an Enemy, move the bullet forward
       setPos(x(),y()-10);
       // if the bullet is off the screen, destroy it
       if (pos().y() < 0){
           scene()->removeItem(this);
           delete this;
       }
}
