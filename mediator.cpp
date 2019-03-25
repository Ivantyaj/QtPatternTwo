#include "mediator.h"

Mediator::Mediator()
{
}

void Mediator::connectToWorkers(const MainWindow * mainWindow)
{
    QObject::connect(mainWindow, &MainWindow::btnRead, &csvWorker, &CSVWorker::getData);
    QObject::connect(&csvWorker, &CSVWorker::signalReadData, mainWindow, &MainWindow::setReadData);
}
