
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>

#include "design.h"
#include "figure.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionCircle_triggered();

    void on_actionSquare_triggered();

    void on_actionPen_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_as_triggered();

    void on_actionClose_triggered();

    void on_actionExit_triggered();

    void on_actionLine_triggered();

    void on_actionStraight_line_triggered();

private:
    enum Figures {LINE = 0, STRAIGHTLINE, CIRCLE, RECTANGLE};

    Ui::MainWindow *ui;
    Design *design;
    QPen *pen;
    QLabel *figType;
    QLabel *mousePos;
    Figures fig;
    int posX;
    int posY;
    bool saved = true;
    QPixmap subPix;
    QVector <Figure*> v;
    QString fileName = "";

    void showContextMenu(const QPoint&);
    void paintEvent(QPaintEvent*);
    void mousePressEvent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*);
    void timerEvent(QTimerEvent*);
    void closeEvent(QCloseEvent*);
    void resizeEvent(QResizeEvent*);

    void deleteAction();
    void designAction();
    void moveAction();
    void rotateAction();

};

#endif // MAINWINDOW_H
