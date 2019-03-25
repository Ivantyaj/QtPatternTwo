#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include "csvworker.h"
#include "xmlworker.h"
#include <QStringList>
#include <QDebug>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
signals:
    void btnRead(FileWorker *);

public slots:
    void setReadData(QStandardItemModel *);

private slots:
    void on_pushButton_clicked();
    void on_pushButtonRead_clicked();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
