#ifndef CSVREADER_H
#define CSVREADER_H

#include "reader.h"
#include <QDebug>
#include "QFile"

class CSVReader : public Reader
{
public:
    CSVReader();
    QStandardItemModel * read();
};

#endif // CSVREADER_H
