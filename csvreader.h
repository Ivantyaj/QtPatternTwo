#ifndef CSVREADER_H
#define CSVREADER_H

#include "reader.h"
#include <QDebug>
#include <QFile>
#include <QFileDialog>

class CSVReader : public Reader
{
public:
    CSVReader();
    QList<QStringList> read();
    void write(QList<QStringList>);
};

#endif // CSVREADER_H
