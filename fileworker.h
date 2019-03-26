#ifndef FILEWORKER_H
#define FILEWORKER_H

#include "reader.h"
#include <QStringList>
#include <QObject>

class FileWorker : public QObject
{
    Q_OBJECT
public:
    FileWorker();
    virtual Reader * createReader() = 0;
    virtual QList<QStringList> getData() final;
    virtual void setData(QList<QStringList>) final;
signals:
    void signalReadData(QList<QStringList>);
    void signalExportData();
};

#endif // FILEWORKER_H
