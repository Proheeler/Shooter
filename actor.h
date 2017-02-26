#ifndef ACTOR_H
#define ACTOR_H
#include <QGraphicsPixmapItem>
#include <QObject>

class Actor:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    void keyPressEvent(QKeyEvent *event);
public slots:
    void spawn();

};

#endif // ACTOR_H
