
#ifndef CIRCLE_H
#define CIRCLE_H

#include "figure.h"


class Circle : public Figure
{
public:
    Circle();
    Circle(int, int, int, int, QPen);
    void draw(QMainWindow*) override;
    void setSpan(int, int, QMainWindow*) override;
    bool containsPoint(QPoint) override;
    void setR(int);
    int getR();

private:
    QPoint center;
    int r;
};

#endif // CIRCLE_H
