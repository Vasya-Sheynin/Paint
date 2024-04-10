
#ifndef FIGURE_H
#define FIGURE_H

#include <QtWidgets>


class Figure
{
public:
    Figure();
    Figure(int, int, QPen);
    void setItemPen(QPen);
    QPen getPen();
    void setAngle(double);
    double getAngle();
    void setTimerEventAngle(double);
    double getTimerEventAngle();
    void setTimerEventRad(double);
    double getTimerEventRad();
    virtual void setSpan(int, int, QMainWindow*) = 0;
    virtual void draw(QMainWindow*) = 0;
    virtual bool containsPoint(QPoint) = 0;
    virtual ~Figure();
    void setTimer(int);
    int& getTimer();
    void setAnimating(bool);
    bool isAnimating();

protected:
    QPen pen;
    QColor color;
    double angle = 0;
    int xSpan = 0;
    int ySpan = 0;
    int width;
    int wh;
    int ww;
    double stretchX;
    double stretchY;
    int myTimer;
    double timerEventRad;
    double timerEventAngle;
    bool animating = false;
};

#endif // FIGURE_H
