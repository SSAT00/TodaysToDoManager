#ifndef DBWORKER_H
#define DBWORKER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

#include "modules.h"

class dbworker
{
private:
    QVector<task> tasks;

    bool first_todays_opening;

    void readTasks();
    void readSettings();

public:
    dbworker();

    QVector<task> getTasks(){return tasks;};
    bool getTodaysOpened(){return !first_todays_opening;};

};

#endif // DBWORKER_H
