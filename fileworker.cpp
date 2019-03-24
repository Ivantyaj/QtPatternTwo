#include "fileworker.h"

FileWorker::FileWorker()
{

}

QStringList FileWorker::getData()
{
    return createReader()->read();
}
