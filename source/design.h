#ifndef DESIGN_H
#define DESIGN_H

#include <QWidget>
#include <QtWidgets>
#include "figure.h"

namespace Ui {
class Design;
}

class Design : public QDialog
{
    Q_OBJECT

public:
    explicit Design(QDialog *parent = nullptr);
    ~Design();
    void setItem(Figure*);

private:
    Ui::Design *ui;
    QColor color;
    Qt::PenStyle lineStyle;
    Figure *fig;

    Qt::PenStyle penStyleFromString(QString);
};

#endif // DESIGN_H
