#include "xmlreader.h"

XMLReader::XMLReader()
{

}

QList<QStringList> XMLReader::read()
{
    qDebug() << "read xml";

    QFile * file = new QFile();
    file->setFileName("E:\\Projects\\Qt\\pattern2\\task.xml");
    QStringList stringList;
    file->open(QFile::ReadOnly | QFile::Text);

    QXmlStreamReader xmlReader;
    xmlReader.setDevice(file);

    QList<QStringList> listTask;

    while(!xmlReader.atEnd())
    {
        QXmlStreamReader::TokenType token = xmlReader.readNext();
        if (token == QXmlStreamReader::StartElement && xmlReader.name() == "record") {
            token = xmlReader.readNext();
            QStringList stringListTask;

            while(token != QXmlStreamReader::EndElement && xmlReader.name() != "record"){
                xmlReader.readNext();

                QString element = xmlReader.readElementText();
                if(element != "" && xmlReader.name() != "record"){
                    stringListTask << element;
                }
                if(element == "" && xmlReader.name() == "worker"){
                    stringListTask << element;
                }
            }
            listTask.append(stringListTask);
        }

    }
    qDebug() << listTask;
    return listTask;
}

void XMLReader::write(QList<QStringList> list)
{
    QString filename = QFileDialog::getSaveFileName(nullptr, ("Save Xml"), ".", ("Xml files (*.xml)"));

    QFile file(filename);
    file.open(QIODevice::WriteOnly);

    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("data-set");
    xmlWriter.writeAttribute("xmlns:xsi", "http://www.w3.org/2001/XMLSchema-instance");

    for(QStringList strList : list){
        xmlWriter.writeStartElement("record");

        xmlWriter.writeStartElement("project");
        xmlWriter.writeCharacters(strList.at(0));
        xmlWriter.writeEndElement();

        xmlWriter.writeStartElement("task");
        xmlWriter.writeCharacters(strList.at(1));
        xmlWriter.writeEndElement();

        xmlWriter.writeStartElement("id");
        xmlWriter.writeCharacters(strList.at(2));
        xmlWriter.writeEndElement();

        xmlWriter.writeStartElement("planned");
        xmlWriter.writeCharacters(strList.at(3));
        xmlWriter.writeEndElement();

        xmlWriter.writeStartElement("worker");
        xmlWriter.writeCharacters(strList.at(4));
        xmlWriter.writeEndElement();

        xmlWriter.writeStartElement("time");
        xmlWriter.writeCharacters(strList.at(5));
        xmlWriter.writeEndElement();

        xmlWriter.writeStartElement("data");
        xmlWriter.writeCharacters(strList.at(6));
        xmlWriter.writeEndElement();

        xmlWriter.writeEndElement();
    }

    xmlWriter.writeEndElement();

    xmlWriter.writeEndDocument();
    file.close();
}
