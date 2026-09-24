#include "dbworker.h"

dbworker::dbworker()
{
    read_db();
}

void dbworker::read_db(){
    {
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("tasks.db");

        if (!db.open()) {
            qDebug() << "Ошибка при открытии базы данных с задачами: " << db.lastError().text();
            return;
        }

        QSqlQuery query(db);

        if (query.exec("SELECT title, subtitle, status, date, start, end, priority FROM task;")){
            while (query.next()) {
                task t;

                t.title = query.value(0).toString();
                t.subtitle = query.value(1).toString();
                t.status = query.value(2).toInt();

                QStringList date_list = query.value(3).toString().split(".");
                t.date = QDate(date_list[0].toInt(), date_list[1].toInt(), date_list[2].toInt());

                QStringList time_start_list = query.value(4).toString().split(":");
                t.start = QTime(time_start_list[0].toInt(), time_start_list[1].toInt(), 0);

                QStringList time_end_list = query.value(5).toString().split(":");
                t.start = QTime(time_end_list[0].toInt(), time_end_list[1].toInt(), 0);

                t.priority = query.value(6).toInt();

                tasks.append(t);
            }
        }
    }
}
