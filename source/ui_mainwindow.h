/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLine;
    QAction *actionStraight_line;
    QAction *actionCircle;
    QAction *actionSquare;
    QAction *actionPen;
    QAction *actionOpen;
    QAction *actionSave_as;
    QAction *actionClose;
    QAction *actionExit;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuFigures;
    QMenu *menuColor;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        actionLine = new QAction(MainWindow);
        actionLine->setObjectName(QString::fromUtf8("actionLine"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/Img/curved line.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLine->setIcon(icon);
        actionStraight_line = new QAction(MainWindow);
        actionStraight_line->setObjectName(QString::fromUtf8("actionStraight_line"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/Img/straight line.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStraight_line->setIcon(icon1);
        actionCircle = new QAction(MainWindow);
        actionCircle->setObjectName(QString::fromUtf8("actionCircle"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/img/Img/circle.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCircle->setIcon(icon2);
        actionSquare = new QAction(MainWindow);
        actionSquare->setObjectName(QString::fromUtf8("actionSquare"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/img/Img/rectangle.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSquare->setIcon(icon3);
        actionPen = new QAction(MainWindow);
        actionPen->setObjectName(QString::fromUtf8("actionPen"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/img/Img/pen.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPen->setIcon(icon4);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/img/Img/open file.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon5);
        actionSave_as = new QAction(MainWindow);
        actionSave_as->setObjectName(QString::fromUtf8("actionSave_as"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/img/Img/save as.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_as->setIcon(icon6);
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/img/Img/close file.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClose->setIcon(icon7);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuFigures = new QMenu(menubar);
        menuFigures->setObjectName(QString::fromUtf8("menuFigures"));
        menuColor = new QMenu(menubar);
        menuColor->setObjectName(QString::fromUtf8("menuColor"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuFigures->menuAction());
        menubar->addAction(menuColor->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave_as);
        menuFile->addAction(actionClose);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuFigures->addAction(actionLine);
        menuFigures->addAction(actionStraight_line);
        menuFigures->addAction(actionCircle);
        menuFigures->addAction(actionSquare);
        menuColor->addAction(actionPen);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionLine->setText(QCoreApplication::translate("MainWindow", "Line", nullptr));
        actionStraight_line->setText(QCoreApplication::translate("MainWindow", "Straight line", nullptr));
        actionCircle->setText(QCoreApplication::translate("MainWindow", "Circle", nullptr));
        actionSquare->setText(QCoreApplication::translate("MainWindow", "Square", nullptr));
        actionPen->setText(QCoreApplication::translate("MainWindow", "Pen", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open...", nullptr));
#if QT_CONFIG(shortcut)
        actionOpen->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave_as->setText(QCoreApplication::translate("MainWindow", "Save as...", nullptr));
#if QT_CONFIG(shortcut)
        actionSave_as->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionClose->setText(QCoreApplication::translate("MainWindow", "Close", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuFigures->setTitle(QCoreApplication::translate("MainWindow", "Figures", nullptr));
        menuColor->setTitle(QCoreApplication::translate("MainWindow", "Color", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
