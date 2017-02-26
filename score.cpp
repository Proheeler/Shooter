#include "score.h"
#include <QGraphicsTextItem>
#include <QGraphicsItem>
#include <QFont>

Score::Score(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
//initialize the score
    score =0;
//set score on screen
    setPlainText(QString("Score: ")+QString::number(score));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Score::increase()
{
    score++;
    setPlainText(QString("Score: ")+QString::number(score));

}

int Score::getScore()
{
    return score;
}
