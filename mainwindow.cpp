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

void MainWindow::setReadData(QStandardItemModel * readModel)
{
    qDebug() << "setSome " << readModel;
    ui->tableView->setModel(readModel);
}
