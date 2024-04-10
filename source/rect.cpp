
#include "rect.h"

Rect::Rect() : pos(0, 0), size(50)
{
}

Rect::Rect(int x, int y, int w, int h, QPen pen) :
    Figure(w, h, pen), pos(x, y),len(std::min({w, h})/4), wid(std::min({w, h})/4)
{
    centre = QPoint(pos.x()+len/2, pos.y()+wid/2);
}

void Rect::draw(QMainWindow *field)
{
    stretchX = (double)field->width()/ww;
    stretchY = (double)field->height()/wh;
    QPainter painter(field);

    painter.save();

    painter.translate(centre.x()*stretchX, centre.y()*stretchY);
    painter.rotate(-angle);
    painter.translate(-centre.x()*stretchX, -centre.y()*stretchY);
    painter.setPen(pen);
    painter.drawRect(pos.x()*stretchX, pos.y()*stretchY, len*std::min(stretchY, stretchX), wid*std::min(stretchY, stretchX));

    painter.restore();
}

bool Rect::containsPoint(QPoint point)
{
    int pointX = (point.x()-centre.x()*stretchX)*qCos(qDegreesToRadians(angle))-(point.y()-centre.y()*stretchY)*qSin(qDegreesToRadians(angle))+centre.x()*stretchX;
    int pointY = (point.x()-centre.x()*stretchX)*qSin(qDegreesToRadians(angle))+(point.y()-centre.y()*stretchY)*qCos(qDegreesToRadians(angle))+centre.y()*stretchY;

    if(len == wid)
        return ((pointX>pos.x()*stretchX-10 && pointX<pos.x()*stretchX+len*std::min(stretchY, stretchX)+10 && abs(pointY-pos.y()*stretchY) < 10) ||
                (pointX>pos.x()*stretchX-10 && pointX<pos.x()*stretchX+len*std::min(stretchY, stretchX)+10 && abs(pointY-pos.y()*stretchY-wid*std::min(stretchY, stretchX)) < 10) ||
                (pointY>pos.y()*stretchY-10 && pointY<pos.y()*stretchY+wid*std::min(stretchY, stretchX)+10 && abs(pointX-pos.x()*stretchX) < 10) ||
                (pointY>pos.y()*stretchY-10 && pointY<pos.y()*stretchY+wid*std::min(stretchY, stretchX)+10 && abs(pointX-pos.x()*stretchX-len*std::min(stretchY, stretchX)) < 10));
    else
        return ((pointX>pos.x()*stretchX-10 && pointX<pos.x()*stretchX+len*stretchX+10 && abs(pointY-pos.y()*stretchY) < 10) ||
                (pointX>pos.x()*stretchX-10 && pointX<pos.x()*stretchX+len*stretchX+10 && abs(pointY-pos.y()*stretchY-wid*stretchY) < 10) ||
                (pointY>pos.y()*stretchY-10 && pointY<pos.y()*stretchY+wid*stretchY+10 && abs(pointX-pos.x()*stretchX) < 10) ||
                (pointY>pos.y()*stretchY-10 && pointY<pos.y()*stretchY+wid*stretchY+10 && abs(pointX-pos.x()*stretchX-len*stretchX) < 10));
}

void Rect::setSpan(int xSpan, int ySpan, QMainWindow* w)
{
    pos = QPoint(xSpan*ww/w->width(), ySpan*wh/w->height());
    centre = QPoint(pos.x()+len/2, pos.y()+wid/2);
}

void Rect::setSize(int a, int b)
{
    len = a;
    wid = b;
    centre = QPoint(pos.x()+len/2, pos.y()+wid/2);
}

QSize Rect::getSize()
{
    return QSize(len, wid);
}
