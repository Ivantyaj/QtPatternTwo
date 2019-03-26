#ifndef READER_H
#define READER_H

#include <QStandardItemModel>
#include <memory>

class Reader
{
public:
    Reader();
    //virtual QStringList readData();    //virtual std::unique_ptr<Reader> createReader() = 0;
    virtual QList<QStringList> read() = 0;
    virtual void write(QList<QStringList>) = 0;
};

#endif // READER_H
