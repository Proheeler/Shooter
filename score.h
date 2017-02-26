#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsTextItem>
class QGraphicsItem;

class Score:public QGraphicsTextItem
{
public:
    explicit Score(QGraphicsItem *parent=0);
    void increase();
    int getScore();
private:
    int score;

};

#endif // SCORE_H
