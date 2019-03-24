#ifndef XMLWORKER_H
#define XMLWORKER_H

#include "fileworker.h"
#include "xmlreader.h"

class XMLWorker : public FileWorker
{
public:
    XMLWorker();
    Reader * createReader();
};

#endif // XMLWORKER_H
