///Imported Headers
#include "mainWindow/mainwindow.h"

///Imported Libraries
#include <QApplication>

//Main Qt App function
int main(int argc, char *argv[])
{
    //Create QApplication object and init construct
    QApplication a(argc, argv);
    //Create MainWindow object
    MainWindow w;
    //Show MainWindow w object
    w.show();

    // QApplication a object executation error
    // 0 if IDLE and >=1 if have an error
    return a.exec();
}
