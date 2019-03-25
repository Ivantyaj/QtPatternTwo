#ifndef MEDIATOR_H
#define MEDIATOR_H

#include <QObject>
#include "mainwindow.h"
//#include "QMainWindow"
#include "fileworker.h"
#include "csvworker.h"

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
};

#endif // MEDIATOR_H
