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

void MainWindow::reloadTable(QList<Task> tasks)
{
    QStandardItemModel * model = new QStandardItemModel();
    model->setColumnCount(7);
    model->setHorizontalHeaderLabels(Task::getHeader());

    for(Task task: tasks){
        QList<QStandardItem *> stdItemList;
        stdItemList.append(new QStandardItem(task.getProjectName()));
        stdItemList.append(new QStandardItem(task.getTaskName()));
        stdItemList.append(new QStandardItem(task.getTaskId()));
        stdItemList.append(new QStandardItem(task.getPlannedHour()));
        stdItemList.append(new QStandardItem(task.getWorkerName()));
        stdItemList.append(new QStandardItem(task.getTime()));
        stdItemList.append(new QStandardItem(task.getDate()));
        model->insertRow(model->rowCount(),stdItemList);
    }

    ui->tableView->setModel(model);
}

QList<QStringList> MainWindow::getTableData()
{
    int column = ui->tableView->model()->columnCount();
    int row = ui->tableView->model()->rowCount();

    //QModelIndex index;

    QList<QStringList> list;

    for(int r = 0; r < row; r++){
        QStringList stringList;
        for(int c = 0; c < column; c++){
            stringList.append(ui->tableView->model()->data(ui->tableView->model()->index(r,c)).toString());
        }
        qDebug() << stringList;
        list.append(stringList);
    }
    return list;
}


void MainWindow::on_pushButtonRead_clicked()
{
    if(ui->comboBoxFile->currentText() == "CSV"){
        emit btnReadCSV();
    }
    if(ui->comboBoxFile->currentText() == "XML"){
        emit btnReadXML();
    }
}

void MainWindow::on_pushButtonExport_clicked()
{
    if(ui->comboBoxFileExport->currentText() == "CSV"){
        emit btnExportCSV(getTableData());
    }
    if(ui->comboBoxFileExport->currentText() == "XML"){
        emit btnExportXML(getTableData());
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
    taskFiltered = taskList;
}

void MainWindow::confirmExport()
{
    QMessageBox::information(this, "Export", "Exported", QMessageBox::Ok);
}

void MainWindow::on_pushButtonFilter_clicked()
{
    //taskFiltered.clear();
    QList<Task> taskListFilteredName;
    taskFiltered.clear();



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
        }
    } else {
        for(Task task: taskListFilteredName){
            taskFiltered.append(task);
        }
    }

    reloadTable(taskFiltered);
}


void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    QString taskId = ui->tableView->model()->data(index.sibling(index.row(),2)).toString();
    ui->lineEditTaskName->setText(taskId);
}

void MainWindow::on_pushButtonSaveTask_clicked()
{
    for(Task &task: taskFiltered){
        if(ui->lineEditTaskName->text() == task.getTaskId()){
            task.setDate(ui->dateEdit->date());
            task.setTime(ui->timeEdit->time());
        }
    }
    reloadTable(taskFiltered);
}


