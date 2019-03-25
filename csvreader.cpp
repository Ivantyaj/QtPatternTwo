#include "csvreader.h"

CSVReader::CSVReader()
{

}

QStandardItemModel * CSVReader::read()
{
//    busList.clear();
//    busListFiltered.clear();
    //TODO
    QFile * file = new QFile();
    file->setFileName("E:\\Projects\\Qt\\pattern2\\task.csv");
    file->open(QFile::ReadOnly | QFile::Text);

    QStandardItemModel * model = new QStandardItemModel();
    model->setColumnCount(10);

    QTextStream in(file);
//    if(!in.atEnd()){
//        QString line = in.readLine();
//        QStringList stringList;
//        for(QString item : line.split(";")){
//            stringList << item;
//        }
//        model->setHorizontalHeaderLabels(stringList);
//        headers = stringList;
//        qDebug() << stringList;
//    }

    while(!in.atEnd()){
        QString line = in.readLine();
        QList<QStandardItem *> stdItemList;
        QStringList stringListBus;
        for(QString item : line.split(";")){
            stringListBus << item;
            stdItemList.append(new QStandardItem(item));
        }
        //addBus(stringListBus);


        model->insertRow(model->rowCount(),stdItemList);
        qDebug() << stdItemList;
    }
    file->close();

    //busListFiltered = busList;

    return model;
}
