#ifndef CSVREADER_H
#define CSVREADER_H

#include "reader.h"

class CSVReader : public Reader
{
public:
    CSVReader();
    QStringList read();
};

#endif // CSVREADER_H
