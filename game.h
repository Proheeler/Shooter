#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include "actor.h"
#include "score.h"
#include "health.h"
#include "Button.h"
#include <QObject>

class QMediaPlayer;
class QGraphicsScene;

class Game:public QGraphicsView
{

public:
    Game(QWidget *parent=0);
    QGraphicsScene *scene;
    Actor *player;
    Score *score;
    Health *health;
    QMediaPlayer *music;
    void drawPanel(int x, int y, int width, int height, QColor color, double opacity);
    void displayGameOverWindow(QString textToDisplay);
public slots:
    void gameOver();
};


#endif // GAME_H
