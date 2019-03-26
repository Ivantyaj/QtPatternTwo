#ifndef MEDIATOR_H
#define MEDIATOR_H

#include <QObject>
#include "mainwindow.h"
//#include "QMainWindow"
#include "fileworker.h"
#include "csvworker.h"
#include "xmlworker.h"

class Mediator : QObject
{
    Q_OBJECT
public:
    Mediator();
    void connectToWorkers(const MainWindow *);
signals:

public slots:

private:
    CSVWorker csvWorker;
    XMLWorker xmlWorker;
};

#endif // MEDIATOR_H
