#include "fileworker.h"

FileWorker::FileWorker()
{

}

QStandardItemModel * FileWorker::getData()
{
    QStandardItemModel * model = createReader()->read();
    emit signalReadData(model);
    return model;
}
