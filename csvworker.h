#ifndef CSVWORKER_H
#define CSVWORKER_H

#include "fileworker.h"
#include "csvreader.h"

class CSVWorker : public FileWorker
{
public:
    CSVWorker();
    Reader * createReader();
};

#endif // CSVWORKER_H
