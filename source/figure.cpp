
#include "figure.h"

Figure::Figure()
{

}

Figure::Figure(int w, int h, QPen pen) :
    ww(w), wh(h), pen(pen), angle(0), timerEventRad(0), timerEventAngle(0)
{

}

void Figure::setItemPen(QPen p)
{
    pen = p;
}

QPen Figure::getPen()
{
    return pen;
}

void Figure::setAngle(double an)
{
    angle = (int)(angle + an) % 360;
}

double Figure::getAngle()
{
    return angle;
}

void Figure::setTimerEventAngle(double an)
{
    timerEventAngle = an;
}

double Figure::getTimerEventAngle()
{
    return timerEventAngle;
}

void Figure::setTimerEventRad(double rad)
{
    timerEventRad = rad;
}

double Figure::getTimerEventRad()
{
    return timerEventRad;
}

Figure::~Figure()
{

}

void Figure::setTimer(int time)
{
    myTimer = time;
}

int& Figure::getTimer()
{
    return myTimer;
}

void Figure::setAnimating(bool val)
{
    animating = val;
}

bool Figure::isAnimating()
{
    return animating;
}

