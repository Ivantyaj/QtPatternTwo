#include "task.h"

Task::Task()
{

}

Task::Task(QStringList list)
{
       this->setFromList(list);
}

void Task::setFromList(const QStringList &list)
{
    projectName = list.at(0);
    taskName = list.at(1);
    taskId = list.at(2).toInt();
    plannedHour = list.at(3).toInt();
    workerName = list.at(4);
}

void Task::setFromItem(QStandardItem *item)
{
    item->columnCount();
}

QStringList Task::getHeader()
{
    return {"Проект", "Задача", "ID", "Трудоемкость", "Ресурс"};
}

QString Task::getProjectName()
{
    return projectName;
}

QString Task::getTaskName()
{
    return taskName;
}

QString Task::getTaskId()
{
    return QString::number(taskId);
}

QString Task::getPlannedHour()
{
    return QString::number(plannedHour);
}

QString Task::getWorkerName()
{
    return workerName;
}
