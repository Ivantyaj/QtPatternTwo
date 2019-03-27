#ifndef XMLREADER_H
#define XMLREADER_H

#include "reader.h"
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QXmlStreamReader>

class XMLReader : public Reader
{
public:
    XMLReader();
    QList<QStringList> read();
    void write(QList<QStringList>);
};

#endif // XMLREADER_H
