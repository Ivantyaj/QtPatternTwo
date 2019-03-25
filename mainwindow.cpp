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


void MainWindow::on_pushButtonRead_clicked()
{
    if(ui->comboBoxFile->currentText() == "CSV"){
        qDebug() << "read btn";
        emit btnRead(new CSVWorker);
    }

}

void MainWindow::setReadData(QList<QStringList> readList)
{
    taskList.clear();
    QStandardItemModel * model = new QStandardItemModel();
    model->setColumnCount(7);

    model->setHorizontalHeaderLabels(Task::getHeader());
    for(QStringList stringList : readList){
        QList<QStandardItem *> stdItemList;
        for(QString stringData : stringList){
            stdItemList.append(new QStandardItem(stringData));
        }
        taskList.append(Task(stringList));
        model->insertRow(model->rowCount(),stdItemList);
    }

    ui->tableView->setModel(model);
    //taskFiltered = taskList;
}

void MainWindow::on_pushButtonFilter_clicked()
{
    //taskFiltered.clear();
    QList<Task> taskListFilteredName;
    QList<Task> taskFiltered;



    if(ui->lineEditName->text() != "" && !ui->radioButtonAll->isChecked()){
        if(ui->radioButtonMy->isChecked()){

            for(Task task: taskList){
                qDebug() << "MY" << ui->lineEditName->text() << task.getWorkerName();
                if(task.getWorkerName() == ui->lineEditName->text())
                    taskListFilteredName.append(task);
            }
        }
        if(ui->radioButtonMyNot->isChecked()){
            qDebug() << "MYNOT";
            for(Task task: taskList){
                if(task.getWorkerName() == ui->lineEditName->text() || task.getWorkerName() == "")
                    taskListFilteredName.append(task);
            }
        }
    } else {
        taskListFilteredName = taskList;
    }




    QString filterString = ui->lineEditFilter->text();
    if(!filterString.isEmpty()){
        switch (ui->comboBoxFilter->currentIndex()) {
        case 0:
            for(Task task: taskListFilteredName){
                if(task.getProjectName() == filterString)
                    taskFiltered.append(task);
            }
            break;
        case 1:
            for(Task task: taskListFilteredName){
                if(task.getTaskName() == filterString)
                    taskFiltered.append(task);
            }
            break;
        case 2:
            for(Task task: taskList){
                if(task.getTaskId() == filterString)
                    taskFiltered.append(task);
            }
            break;
        case 3:
            for(Task task: taskListFilteredName){
                if(task.getPlannedHour() == filterString)
                    taskFiltered.append(task);
            }
            break;
            //    case 4:
            //        for(Task task: taskList){
            //            if(task.getWorkerName() == filterString)
            //                taskFiltered.append(task);
            //        }
            //        break;
        }
    } else {
        for(Task task: taskListFilteredName){
            taskFiltered.append(task);
        }
    }

    QStandardItemModel * model = new QStandardItemModel();
    model->setColumnCount(7);
    model->setHorizontalHeaderLabels(Task::getHeader());

    for(Task task: taskFiltered){
        QList<QStandardItem *> stdItemList;
        stdItemList.append(new QStandardItem(task.getProjectName()));
        stdItemList.append(new QStandardItem(task.getTaskName()));
        stdItemList.append(new QStandardItem(task.getTaskId()));
        stdItemList.append(new QStandardItem(task.getPlannedHour()));
        stdItemList.append(new QStandardItem(task.getWorkerName()));
        model->insertRow(model->rowCount(),stdItemList);
    }

    ui->tableView->setModel(model);
}


void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    //qDebug() << index.row() << ui->tableView->model()->data(index.sibling(index.row(),4)).toString();
    QString taskId = ui->tableView->model()->data(index.sibling(index.row(),2)).toString();
    ui->lineEditTaskName->setText(taskId);
}
