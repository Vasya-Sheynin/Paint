
#include "line.h"

Line::Line()
{

}

Line::Line(int w, int h, QPen pen) : Figure(w, h, pen)
{
}

void Line::draw(QMainWindow *field)
{
    stretchX = (double)field->width()/ww;
    stretchY = (double)field->height()/wh;
    QPainter painter(field);
    painter.translate(points[0].x()*stretchX, points[0].y()*stretchY);
    painter.rotate(-angle);
    painter.translate(-points[0].x()*stretchX, -points[0].y()*stretchY);
    painter.setPen(pen);
    for(int i = 0; i < points.size()-1; i++)
        painter.drawLine(points[i].x()*stretchX, points[i].y()*stretchY, points[i+1].x()*stretchX, points[i+1].y()*stretchY);
}

void Line::addPoint(int x, int y)
{
    points.push_back(QPoint(x, y));
}

bool Line::containsPoint(QPoint point)
{
    for(int i = 0; i < points.size(); i++)
        if((abs((points[i].x()*stretchX-points[0].x()*stretchX)*qCos(qDegreesToRadians(angle))+(points[i].y()*stretchY-points[0].y()*stretchY)*qSin(qDegreesToRadians(angle))+points[0].x()*stretchX-point.x()) < 10) &&
           (abs(-(points[i].x()*stretchX-points[0].x()*stretchX)*qSin(qDegreesToRadians(angle))+(points[i].y()*stretchY-points[0].y()*stretchY)*qCos(qDegreesToRadians(angle))+points[0].y()*stretchY-point.y()) < 10))
            return true;
    return false;
}

void Line::setSpan(int xSpan, int ySpan, QMainWindow* w)
{
    int deltaX = xSpan - points[0].x()*stretchX;
    int deltaY = ySpan - points[0].y()*stretchY;
    for(int i = 0; i < points.size(); i++)
        points[i] = QPoint((points[i].x()*stretchX+deltaX)*ww/w->width(), (points[i].y()*stretchY+deltaY)*wh/w->height());
}

void Line::setTimerEventPen(QPen p)
{
    timerEventPen = p;
}

QPen Line::getTimerEventPen()
{
    return timerEventPen;
}
