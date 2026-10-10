#ifndef DBWORKER_H
#define DBWORKER_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

#include "modules.h"

class dbworker : public QObject
{
    Q_OBJECT

private:
    QVector<task> tasks;
    bool first_todays_opening;
    bool isdark;

    void readTasks();
    void readSettings();

public:
    explicit dbworker(QObject *parent = nullptr);

    QVector<task> getTasks() { return tasks; }
    bool getTheme(){return isdark;}

    void setTheme(bool isDark);
    void setNewTask(task);
    void setNewStatus(QString);
};

#endif // DBWORKER_H
