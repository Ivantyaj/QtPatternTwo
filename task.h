#ifndef TASK_H
#define TASK_H

#include <QString>
#include <QStringList>
#include <QTime>
#include <QDate>

class Task
{
public:
    Task();

    void setFromList(const QStringList & list);
    void setTime(QTime);
    void setDate(QDate);

    //TODO
    QStringList getStringList() {}

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
