#ifndef XMLREADER_H
#define XMLREADER_H

#include "reader.h"

class XMLReader : public Reader
{
public:
    XMLReader();
    QStringList read();
};

#endif // XMLREADER_H
