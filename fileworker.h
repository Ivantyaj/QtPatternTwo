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
signals:
    void signalReadData(QList<QStringList>);
};

#endif // FILEWORKER_H
