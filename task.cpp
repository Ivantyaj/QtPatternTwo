#include "task.h"

Task::Task()
{

}

void Task::setFromList(const QStringList &list)
{
    projectName = list.at(0);
    taskName = list.at(1);
    taskId = list.at(2).toInt();
    plannedHour = list.at(3).toInt();
    wokerName = list.at(4);
}
