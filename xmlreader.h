#ifndef XMLREADER_H
#define XMLREADER_H

#include "reader.h"

class XMLReader : public Reader
{
public:
    XMLReader();
    QStandardItemModel* read();
};

#endif // XMLREADER_H
