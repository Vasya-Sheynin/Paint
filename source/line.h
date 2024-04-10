
#ifndef LINE_H
#define LINE_H

#include "figure.h"


class Line : public Figure
{
public:
    Line();
    Line(int, int, QPen);
    void draw(QMainWindow*) override;
    void addPoint(int, int);
    bool containsPoint(QPoint) override;
    void setSpan(int, int, QMainWindow*) override;
    void setTimerEventPen(QPen);
    QPen getTimerEventPen();

private:
    QVector <QPoint> points;
    QPen timerEventPen;
};

#endif // LINE_H
