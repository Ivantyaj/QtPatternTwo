#include "fileworker.h"

FileWorker::FileWorker()
{

}

QList<QStringList> FileWorker::getData()
{
    QList<QStringList> model = createReader()->read();
    emit signalReadData(model);
    return model;
}
