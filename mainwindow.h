#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include "csvworker.h"
#include "xmlworker.h"
#include <QStringList>
#include <QDebug>
#include "task.h"
#include <QMessageBox>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QList<Task> taskList;
    QList<Task> taskFiltered;
    //QList<Task> taskFiltered;

    void reloadTable(QList<Task>);
    QList<QStringList> getTableData();
signals:
    void btnReadCSV();
    void btnExportCSV(QList<QStringList>);

    void btnReadXML();
    void btnExportXML(QList<QStringList>);

public slots:
    void setReadData(QList<QStringList>);
    void confirmExport();

private slots:
    void on_pushButtonRead_clicked();
    void on_pushButtonFilter_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButtonSaveTask_clicked();

    void on_pushButtonExport_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
