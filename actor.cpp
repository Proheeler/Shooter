#include "actor.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include "bullet.h"
#include <enemies.h>

void Actor::keyPressEvent(QKeyEvent *event)
{
    if (event->key()== Qt::Key_Left){
        if (pos().x()>0)
        setPos(x()-10,y());

    }
    if (event->key()== Qt::Key_Right){
        if (pos().x() + 100 < 800)
        setPos(x()+10,y());
    }

    if (event->key()== Qt::Key_Space){
        Bullet *bullet=new Bullet();
        bullet->setPos(x(),y());
        scene()->addItem(bullet);
    }

}

void Actor::spawn()
{
Enemies *enemy= new Enemies();
scene()->addItem(enemy);
}

