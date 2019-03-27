#include "csvreader.h"

CSVReader::CSVReader()
{

}

QList<QStringList> CSVReader::read()
{
    QFile * file = new QFile();
    file->setFileName("E:\\Projects\\Qt\\pattern2\\task.csv");
    file->open(QFile::ReadOnly | QFile::Text);

    QTextStream in(file);

    QList<QStringList> stdItemList;
    while(!in.atEnd()){
        QString line = in.readLine();

        QStringList stringListBus;
        for(QString item : line.split(";")){
            stringListBus << item;
        }
        stdItemList.append(stringListBus);
    }
    file->close();
    return stdItemList;
}

void CSVReader::write(QList<QStringList> list)
{
    QString filename = QFileDialog::getSaveFileName(nullptr, ("Save Csv"), ".", ("Csv files (*.csv)"));

    QFile file(filename);

    if (file.open(QFile::WriteOnly|QFile::Truncate))
    {
        QTextStream stream(&file);

        for(QStringList strList : list){
            for(QString str : strList){
                stream << str << ";";
            }
            stream << "\n";
        }

        file.close();
    }
}
