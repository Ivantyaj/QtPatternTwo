#include "mediator.h"

Mediator::Mediator()
{
}

void Mediator::connectToWorkers(const MainWindow * mainWindow)
{
    QObject::connect(mainWindow, &MainWindow::btnReadCSV, &csvWorker, &CSVWorker::getData);
    QObject::connect(&csvWorker, &CSVWorker::signalReadData, mainWindow, &MainWindow::setReadData);

    QObject::connect(mainWindow, &MainWindow::btnReadXML, &xmlWorker, &XMLWorker::getData);
    QObject::connect(&xmlWorker, &XMLWorker::signalReadData, mainWindow, &MainWindow::setReadData);

    QObject::connect(mainWindow, &MainWindow::btnExportCSV, &csvWorker, &CSVWorker::setData);
    QObject::connect(&csvWorker, &CSVWorker::signalExportData, mainWindow, &MainWindow::confirmExport);

    QObject::connect(mainWindow, &MainWindow::btnExportXML, &xmlWorker, &XMLWorker::setData);
    QObject::connect(&xmlWorker, &XMLWorker::signalExportData, mainWindow, &MainWindow::confirmExport);
}
