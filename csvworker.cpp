#include "csvworker.h"

CSVWorker::CSVWorker()
{

}

Reader *CSVWorker::createReader()
{
    return new CSVReader();
}
