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

    void read_db();

public:
    dbworker();

};

#endif // DBWORKER_H
