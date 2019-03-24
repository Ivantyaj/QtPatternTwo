#include "xmlworker.h"

XMLWorker::XMLWorker()
{

}

Reader * XMLWorker::createReader()
{
    return new XMLReader();
}
