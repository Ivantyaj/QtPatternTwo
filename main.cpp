#include "mainwindow.h"
#include <QApplication>
#include "mediator.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    Mediator mediator;
    mediator.connectToWorkers(&w);

    w.show();

    return a.exec();
}
