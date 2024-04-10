
#include "circle.h"

Circle::Circle() : center(0, 0), r(20)
{

}

Circle::Circle(int x, int y, int w, int h, QPen pen) : Figure(w, h, pen), center(x, y), r(std::min({w, h})/20)
{
}

void Circle::draw(QMainWindow *field)
{
    stretchX = (double)field->width()/ww;
    stretchY = (double)field->height()/wh;
    QPoint p(center.x()*stretchX, center.y()*stretchY);


    QPainter painter(field);
    painter.save();

    painter.translate(center.x()*stretchX, center.y()*stretchY);
    painter.rotate(angle);
    painter.translate(-center.x()*stretchX, -center.y()*stretchY);
    painter.setPen(pen);
    int tmpR = r*std::min(stretchY, stretchX);
    painter.drawEllipse(p, tmpR, tmpR);

    painter.restore();

}

void Circle::setSpan(int xSpan, int ySpan, QMainWindow* w)
{
    center = QPoint(xSpan*ww/w->width(), ySpan*wh/w->height());
}

bool Circle::containsPoint(QPoint point)
{
    int cx = center.x()*stretchX-point.x();
    int cy = center.y()*stretchY-point.y();
    return((pow(cx, 2) + pow(cy, 2) > pow(r*std::min(stretchY, stretchX) - 10, 2)) && (pow(cx, 2) + pow(cy, 2) < pow(r*std::min(stretchY, stretchX) + 10, 2)));
}

void Circle::setR(int rad)
{
    r = rad;
}

int Circle::getR()
{
    return r;
}

