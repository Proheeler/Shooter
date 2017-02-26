#ifndef ENEMIES_H
#define ENEMIES_H


#include <QGraphicsPixmapItem>
#include <QObject>


class Enemies:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Enemies();
public slots:
    void move();
};

#endif // ENEMIES_H
