
#ifndef STRAIGHTLINE_H
#define STRAIGHTLINE_H

#include "figure.h"


class StraightLine : public Figure
{
public:
    StraightLine();
    StraightLine(int, int, int, int, QPen);
    void draw(QMainWindow*) override;
    void setFirstPos(int, int);
    void setLastPos(int, int);
    bool containsPoint(QPoint) override;
    void setSpan(int, int, QMainWindow*) override;
    QPoint getFirstPos();
    QPoint getLastPos();
    QPoint getTimerEventPointA();
    void setTimerEventPointA(QPoint);
    QPoint getTimerEventPointB();
    void setTimerEventPointB(QPoint);

private:
    QPoint firstPos;
    QPoint lastPos;
    QPoint newLastPos;
    QPoint timerEventPointA;
    QPoint timerEventPointB;
};

#endif // STRAIGHTLINE_H
