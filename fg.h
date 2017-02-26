#ifndef FG_H
#define FG_H

#include <QWidget>

namespace Ui {
class FG;
}

class FG : public QWidget
{
    Q_OBJECT

public:
    explicit FG(QWidget *parent = 0);
    ~FG();

private:
    Ui::FG *ui;
};

#endif // FG_H
