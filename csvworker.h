#ifndef CSVWORKER_H
#define CSVWORKER_H

#include "fileworker.h"
#include "csvreader.h"
#include <QObject>

class CSVWorker :public FileWorker
{
public:
    CSVWorker();
    Reader * createReader();
};

#endif // CSVWORKER_H
