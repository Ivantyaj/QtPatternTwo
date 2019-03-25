#ifndef READER_H
#define READER_H

#include <QStandardItemModel>
#include <memory>

class Reader
{
public:
    Reader();
    //virtual QStringList readData();    //virtual std::unique_ptr<Reader> createReader() = 0;
    virtual QStandardItemModel * read() = 0;
};

#endif // READER_H
