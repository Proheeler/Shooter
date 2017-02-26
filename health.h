#ifndef HEALTH_H
#define HEALTH_H
#include <QGraphicsItem>
#include <QFont>
#include <QObject>
#include <QGraphicsView>

class Health:public QGraphicsTextItem
{
    Q_OBJECT
public:
    explicit Health(QGraphicsItem *parent=0);
    void decrease();
    int getHealth();

private:
    int health;
signals:
    void die();

};

#endif // HEALTH_H
