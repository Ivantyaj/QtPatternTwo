#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include "csvworker.h"
#include "xmlworker.h"
#include <QStringList>
#include <QDebug>
#include "task.h"


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
    //QList<Task> taskFiltered;

signals:
    void btnRead(FileWorker *);

public slots:
    void setReadData(QList<QStringList>);

private slots:
    void on_pushButtonRead_clicked();
    void on_pushButtonFilter_clicked();

    void on_tableView_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
