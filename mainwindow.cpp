#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::on_pushButtonRead_clicked()
{
    if(ui->comboBoxFile->currentText() == "CSV"){
        qDebug() << "read btn";
        emit btnRead(new CSVWorker);
    }

}

void MainWindow::setReadData(QList<QStringList> readList)
{
//    qDebug() << "setSome " << readModel;
//    for(int i = 0; i < readModel->rowCount(); i++){
//        for(QStandardItem * item: readModel->takeRow(i)){
//            //item->takeColumn()
//            //
////            qDebug() << item->takeChild(0, 1);
////            qDebug() << item->takeChild(0, 2);
////            qDebug() << item->takeChild(0, 3);
//        }
//    }
    //ui->tableView->setModel(readModel);
    QStandardItemModel * model = new QStandardItemModel();
    model->setColumnCount(5);

    for(QStringList stringList : readList){
        QList<QStandardItem *> stdItemList;
        for(QString stringData : stringList){
            stdItemList.append(new QStandardItem(stringData));
        }
        model->insertRow(model->rowCount(),stdItemList);
    }

    ui->tableView->setModel(model);

}
