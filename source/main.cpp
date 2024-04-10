
#include "mainwindow.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setMinimumSize(1100, 700);
    w.setWindowTitle("Paint Device pre-alpha 0.2");
    w.show();
    return a.exec();
}
