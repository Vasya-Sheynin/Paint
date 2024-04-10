
#ifndef RECT_H
#define RECT_H

#include "figure.h"


class Rect : public Figure
{
public:
    Rect();
    Rect(int, int, int, int, QPen);
    void draw(QMainWindow*) override;
    bool containsPoint(QPoint) override;
    void setSpan(int, int, QMainWindow*) override;
    void setSize(int, int);
    QSize getSize();

private:
    QPoint pos;
    QPoint centre;
    double size;
    int len;
    int wid;
};

#endif // RECT_H
