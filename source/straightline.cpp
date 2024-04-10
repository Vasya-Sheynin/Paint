
#include "straightline.h"

StraightLine::StraightLine()
{

}

StraightLine::StraightLine(int x, int y, int w, int h, QPen pen) : Figure(w, h, pen), lastPos(x, y)
{
}

void StraightLine::draw(QMainWindow *field)
{
    stretchX = (double)field->width()/ww;
    stretchY = (double)field->height()/wh;
    int pointX = (lastPos.x()*stretchX-firstPos.x()*stretchX)*qCos(qDegreesToRadians(angle))+(lastPos.y()*stretchY-firstPos.y()*stretchY)*qSin(qDegreesToRadians(angle))+firstPos.x()*stretchX;
    int pointY = -(lastPos.x()*stretchX-firstPos.x()*stretchX)*qSin(qDegreesToRadians(angle))+(lastPos.y()*stretchY-firstPos.y()*stretchY)*qCos(qDegreesToRadians(angle))+firstPos.y()*stretchY;
    newLastPos = QPoint(pointX, pointY);

    QPainter painter(field);
    painter.setPen(pen);
    painter.drawLine(firstPos.x()*stretchX, firstPos.y()*stretchY, newLastPos.x(), newLastPos.y());
}

void StraightLine::setFirstPos(int x, int y)
{
    firstPos = QPoint(x, y);
}

void StraightLine::setLastPos(int x, int y)
{
    lastPos = QPoint(x, y);
}

bool StraightLine::containsPoint(QPoint point)
{

    double t = (point.x()*(newLastPos.y()-firstPos.y()*stretchY)+point.y()*(firstPos.x()*stretchX-newLastPos.x())+newLastPos.x()*firstPos.y()*stretchY-newLastPos.y()*firstPos.x()*stretchX)/
               (pow((newLastPos.x()-firstPos.x()*stretchX),2)+pow((newLastPos.y()-firstPos.y()*stretchY),2));
    double x0 = point.x()+t*(firstPos.y()*stretchY-newLastPos.y());
    double y0 = point.y()+t*(newLastPos.x()-firstPos.x()*stretchX);
    double usl = (x0-firstPos.x()*stretchX)/(newLastPos.x()-firstPos.x()*stretchX);
    double dlin = sqrt(pow((point.x()-x0),2) + pow((point.y()-y0),2));
    return (usl >= 0 && usl <= 1 && dlin <= 10);
}

void StraightLine::setSpan(int xSpan, int ySpan, QMainWindow* w)
{
    int deltaX = lastPos.x() - firstPos.x();
    int deltaY = lastPos.y() - firstPos.y();
    firstPos = QPoint(xSpan*ww/w->width(), ySpan*wh/w->height());
    lastPos = QPoint(firstPos.x()+deltaX, firstPos.y()+deltaY);
}

QPoint StraightLine::getFirstPos()
{
    return firstPos;
}

QPoint StraightLine::getLastPos()
{
    return lastPos;
}


void StraightLine::setTimerEventPointA(QPoint p)
{
    timerEventPointA = p;
}

QPoint StraightLine::getTimerEventPointA()
{
    return timerEventPointA;
}

void StraightLine::setTimerEventPointB(QPoint p)
{
    timerEventPointB = p;
}

QPoint StraightLine::getTimerEventPointB()
{
    return timerEventPointB;
}
