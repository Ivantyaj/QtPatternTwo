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

void FileWorker::setData(QList<QStringList> stringList)
{
    createReader()->write(stringList);
    emit signalExportData();
}
