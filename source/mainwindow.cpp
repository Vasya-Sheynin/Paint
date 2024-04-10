
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "line.h"
#include "straightline.h"
#include "rect.h"
#include "circle.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->actionOpen->setEnabled(false);
    ui->actionClose->setEnabled(false);

    this->setMouseTracking(true);
    centralWidget()->setMouseTracking(true);

    figType = new QLabel("Line");
    mousePos = new QLabel;
    statusBar()->addWidget(figType);
    statusBar()->addWidget(mousePos);

    pen = new QPen(Qt::black, 4);
    fig = Figures::LINE;

    this->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, &QWidget::customContextMenuRequested,this, &MainWindow::showContextMenu);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionLine_triggered()
{
    fig = Figures::LINE;
    figType->setText("<center> Line </center>");
}

void MainWindow::on_actionStraight_line_triggered()
{
    fig = Figures::STRAIGHTLINE;
    figType->setText("<center> Straight Line </center>");
}

void MainWindow::on_actionCircle_triggered()
{
    fig = Figures::CIRCLE;
    figType->setText("<center> Circle </center>");
}


void MainWindow::on_actionSquare_triggered()
{
    fig = Figures::RECTANGLE;
    figType->setText("<center> Rectangle </center>");
}


void MainWindow::on_actionPen_triggered()
{
    pen->setColor(QColorDialog::getColor());
}


void MainWindow::on_actionOpen_triggered()
{
    fileName = QFileDialog::getOpenFileName(this, "open a file", QDir::homePath(), "Image Files (*.png *.jpg *.bmp)");
    if(!fileName.isEmpty())
    {
        v.clear();
        QPixmap bkgnd(fileName);
        bkgnd = bkgnd.scaled(size(), Qt::IgnoreAspectRatio);
        QPalette p;
        p.setBrush(QPalette::Window, bkgnd);
        setPalette(p);
    }
}

void MainWindow::on_actionSave_as_triggered()
{
    fileName = QFileDialog::getSaveFileName(this, "Save a file", QDir::homePath(), "Image Files (*.png *.jpg *.bmp)");
    if(!fileName.isEmpty()) {

        QPixmap pixmap = this->grab();
        QPixmap subPix = pixmap.copy(QRect(0, 25, pixmap.width(), pixmap.height()-50));
        subPix.save(fileName);

    ui->actionOpen->setEnabled(true);
    ui->actionClose->setEnabled(true);
    saved = true;
    }
}


void MainWindow::closeEvent(QCloseEvent*)
{
    on_actionExit_triggered();
}

void MainWindow::resizeEvent(QResizeEvent*)
{
    if(!fileName.isEmpty())
    {
    QPixmap bkgnd(fileName);
    bkgnd = bkgnd.scaled(size(), Qt::IgnoreAspectRatio);
    QPalette p;
    p.setBrush(QPalette::Window, bkgnd);
    setPalette(p);
    }
}



void MainWindow::on_actionClose_triggered()
{
    if(!saved)
    {
        on_actionSave_as_triggered();
    }
    v.clear();
    update();
}



void MainWindow::on_actionExit_triggered()
{
    if(!saved)
    {
        if (QMessageBox::question(this, "Are you leaving?", "Would you like to save image?", QMessageBox::Yes | QMessageBox::No) == QMessageBox::No)
            QApplication::quit();
        else {
            on_actionSave_as_triggered();
            QApplication::quit();
        }
    }
}


void MainWindow::paintEvent(QPaintEvent*)
{
    for(int i = 0; i < v.size(); i++)
    {
        v[i]->draw(this);
    }
}

void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    posX = ev->x();
    posY = ev->y();
    if(ev->button() == Qt::LeftButton)
    {

        switch(fig)
        {
        case Figures::STRAIGHTLINE:
        {
            v.push_back(new class StraightLine(posX, posY, width(), height(), *pen));
            dynamic_cast<class StraightLine*>(v[v.size()-1])->setFirstPos(posX, posY);
            break;
        }
        case Figures::LINE:
        {
            v.push_back(new class Line(width(), height(), *pen));
            dynamic_cast<class Line*>(v[v.size()-1])->addPoint(posX, posY);
            break;
        }
        case Figures::CIRCLE:
        {
            v.push_back(new class Circle(posX, posY, width(), height(), *pen));
            break;
        }
        case Figures::RECTANGLE:
        {
            v.push_back(new class Rect(posX, posY, width(), height(), *pen));
            break;
        }
        }
        v[v.size()-1]->setItemPen(*pen);
        repaint();
        saved = false;
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *ev)
{
    posX = ev->x();
    posY = ev->y();
    mousePos->setText(QString::number(posX)+":"+QString::number(posY));
    if(ev->buttons() & Qt::LeftButton)
    {
        switch(fig)
        {
        case(Figures::STRAIGHTLINE):
        {
            dynamic_cast<class StraightLine*>(v[v.size()-1])->setLastPos(posX, posY);
            update();
            break;
        }
        case(Figures::LINE):
        {
            dynamic_cast<class Line*>(v[v.size()-1])->addPoint(posX, posY);
            update();
            break;
        }
        default:
        {}
        }
    }
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    for(int i = 0; i < v.size(); i++)
    {
        if (event->timerId() == v[i]->getTimer())
        {
            v[i]->setAnimating(true);
            if (dynamic_cast<Circle*>(v[i]))
            {
                v[i]->setTimerEventAngle(v[i]->getTimerEventAngle()+1);
                dynamic_cast<Circle*>(v[i])->setR(v[i]->getTimerEventRad() * (1 + abs(qSin(qDegreesToRadians(v[i]->getTimerEventAngle())))));
                if(v[i]->getTimerEventAngle() == 360)
                {
                    killTimer(v[i]->getTimer());
                    v[i]->setTimer(-1);
                    v[i]->setAnimating(false);
                }
            }
            if (dynamic_cast<Rect*>(v[i]))
            {
                v[i]->setTimerEventAngle(v[i]->getTimerEventAngle()+1);
                v[i]->setAngle(v[i]->getTimerEventAngle());
                if(v[i]->getTimerEventAngle() == 80)
                {
                    killTimer(v[i]->getTimer());
                    v[i]->setTimer(-1);
                    v[i]->setAnimating(false);
                }
            }
            if (dynamic_cast<Line*>(v[i]))
            {
                v[i]->setTimerEventAngle(v[i]->getTimerEventAngle()+1);
                v[i]->setAngle(v[i]->getTimerEventAngle());
                QRandomGenerator::securelySeeded();
                int r = QRandomGenerator::global()->bounded(0, 256);
                int g = QRandomGenerator::global()->bounded(0, 256);
                int b = QRandomGenerator::global()->bounded(0, 256);
                int w = QRandomGenerator::global()->bounded(1, 10);
                v[i]->setItemPen(QPen(QColor(r, g, b), w));
                if(v[i]->getTimerEventAngle() == 80)
                {
                    killTimer(v[i]->getTimer());
                    v[i]->setTimer(-1);
                    v[i]->setItemPen(dynamic_cast<Line*>(v[i])->getTimerEventPen());
                    v[i]->setAnimating(false);
                }
            }
            if (dynamic_cast<StraightLine*>(v[i]))
            {
                v[i]->setTimerEventAngle(v[i]->getTimerEventAngle()+1);
                QRandomGenerator::securelySeeded();
                dynamic_cast<StraightLine*>(v[i])->setFirstPos
                    (QRandomGenerator::global()->bounded(0, width()), QRandomGenerator::global()->bounded(0, height()));
                dynamic_cast<StraightLine*>(v[i])->setLastPos
                    (QRandomGenerator::global()->bounded(0, width()), QRandomGenerator::global()->bounded(0, height()));
                if(v[i]->getTimerEventAngle() == 80)
                {
                    killTimer(v[i]->getTimer());
                    v[i]->setTimer(-1);
                    dynamic_cast<StraightLine*>(v[i])->setFirstPos(dynamic_cast<StraightLine*>(v[i])->getTimerEventPointA().x(),
                                                                    dynamic_cast<StraightLine*>(v[i])->getTimerEventPointA().y());
                    dynamic_cast<StraightLine*>(v[i])->setLastPos(dynamic_cast<StraightLine*>(v[i])->getTimerEventPointB().x(),
                                                                   dynamic_cast<StraightLine*>(v[i])->getTimerEventPointB().y());
                    v[i]->setAnimating(false);
                }
            }
            update();
        }
    }

}

void MainWindow::showContextMenu(const QPoint &pos)
{

    QMenu contextMenu(this);
    QAction *move = new QAction("Move", this);
    QAction *rotate = new QAction("Rotate", this);
    QAction *del = new QAction("Delete", this);
    QAction *des = new QAction("Design", this);
    QAction *animate = new QAction("Animate", this);

    move->setIcon(QIcon(":/img/Img/move.png"));
    rotate->setIcon(QIcon(":/img/Img/rotate.png"));
    del->setIcon(QIcon(":/img/Img/delete.png"));
    des->setIcon(QIcon(":/img/Img/design.png"));
    animate->setIcon(QIcon(":/img/Img/animate.png"));

    for(int i = v.size() - 1; i >= 0; i--)
        if(v[i]->containsPoint(QPoint(posX, posY)) && !v[i]->isAnimating())
    {
        contextMenu.addAction(move);
        contextMenu.addAction(rotate);
        contextMenu.addAction(del);
        contextMenu.addAction(des);
        contextMenu.addAction(animate);
        connect(del, &QAction::triggered, this, [=](){v.removeAt(i); update(); saved = false;});
        connect(rotate, &QAction::triggered, this, [=](){
            v[i]->setAngle(QInputDialog::getDouble(0, "Angle setup", "Enter angle: 0 - 360", 0));
            update();
            saved = false;
        });

        connect(move, &QAction::triggered, this, [=](){
            QDialog *w = new QDialog;
            w->setFixedSize(200, 200);
            QVBoxLayout *vbox = new QVBoxLayout(w);
            QLineEdit *line1 = new QLineEdit;
            QLineEdit *line2 = new QLineEdit;
            QLabel *lbl1 = new QLabel("<center> X: </center>");
            QLabel *lbl2 = new QLabel("<center> Y: </center>");
            QPushButton *btn = new QPushButton("Apply");
            QRegExp regexWid("^(\\d{3})$");
            QRegExp regexHei("^[0-8]\\d{2}$");
            QValidator *valWid = new QRegExpValidator(regexWid);
            QValidator *valHei = new QRegExpValidator(regexHei);

            line1->setValidator(valWid);
            line2->setValidator(valHei);

            vbox->addWidget(lbl1);
            vbox->addWidget(line1);
            vbox->addWidget(lbl2);
            vbox->addWidget(line2);
            vbox->addWidget(btn);

            connect(btn, &QPushButton::clicked, this, [=](){
                v[i]->setSpan(line1->text().toInt(), line2->text().toInt(), this);
                update();
                saved = false;
                w->close();
            });

            w->exec();
        });
        connect(des, &QAction::triggered, this, [=](){
            design = new Design;
            design->setItem(v[i]);
            design->exec();
            saved = false;
        });

        connect(animate, &QAction::triggered, this, [=](){
            if(dynamic_cast<Circle*>(v[i]))
            {
                v[i]->setTimer(startTimer(10));
                v[i]->setTimerEventRad(dynamic_cast<Circle*>(v[i])->getR());
                v[i]->setTimerEventAngle(0);
            }
            if (dynamic_cast<Rect*>(v[i]))
            {
                v[i]->setTimer(startTimer(30));
                v[i]->setTimerEventAngle(0);
            }
            if (dynamic_cast<Line*>(v[i]))
            {
                v[i]->setTimer(startTimer(30));
                v[i]->setTimerEventAngle(0);
                dynamic_cast<Line*>(v[i])->setTimerEventPen(v[i]->getPen());
            }
            if (dynamic_cast<StraightLine*>(v[i]))
            {
                v[i]->setTimer(startTimer(30));
                v[i]->setTimerEventAngle(0);
                dynamic_cast<StraightLine*>(v[i])->setTimerEventPointA(dynamic_cast<StraightLine*>(v[i])->getFirstPos());
                dynamic_cast<StraightLine*>(v[i])->setTimerEventPointB(dynamic_cast<StraightLine*>(v[i])->getLastPos());
            }
        });
        contextMenu.exec(mapToGlobal(pos));
        break;
    }
}
