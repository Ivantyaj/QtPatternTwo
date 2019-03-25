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

    void setFromList(const QStringList & list);
    void setTime(QTime);
    void setDate(QDate);

    //TODO
    QStringList getStringList() {}
    void setFromItem(QStandardItem * item);

private:
    QString projectName;
    QString taskName;
    int taskId;
    int plannedHour;
    QString wokerName;

    QTime time;
    QDate date;
};

#endif // TASK_H
