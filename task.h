#ifndef TASK_H
#define TASK_H

#include <QString>
#include <QStringList>
#include <QTime>
#include <QDate>
#include <QStandardItem>

class Task
{
public:
    Task();
    Task(QStringList);

    void setFromList(const QStringList & list);
    void setTime(QTime);
    void setDate(QDate);

    //TODO
    QStringList getStringList() {}
    void setFromItem(QStandardItem * item);
    static QStringList getHeader();

    QString getProjectName();
    QString getTaskName();
    QString getTaskId();
    QString getPlannedHour();
    QString getWorkerName();

private:
    QString projectName;
    QString taskName;
    int taskId;
    int plannedHour;
    QString workerName;

    QTime time;
    QDate date;
};

#endif // TASK_H
