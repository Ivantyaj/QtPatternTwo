#ifndef FILEWORKER_H
#define FILEWORKER_H

#include "reader.h"
#include <QStringList>

class FileWorker
{
public:
    FileWorker();
    virtual Reader * createReader() = 0;
    virtual QStringList getData() final;
};

#endif // FILEWORKER_H
