#include "dbworker.h"

dbworker::dbworker()
{
    first_todays_opening = false;
    readTasks();
    readSettings();
}

void dbworker::readTasks(){

    {
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("tasks.db");

        if (!db.open()) {
            qDebug() << "Ошибка при открытии базы данных с задачами: " << db.lastError().text();
            return;
        }

        QSqlQuery query(db);

        if (query.exec("SELECT title, subtitle, status, date, start, end, priority FROM Task;")){
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
        query.clear();
    }
    QSqlDatabase::removeDatabase(QSqlDatabase::defaultConnection);

}


void dbworker::readSettings(){

    QDate date;
    QDate today = QDate::currentDate();

    {
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("tasks.db");

        if (!db.open()) {
            qDebug() << "Ошибка при открытии базы данных с задачами:" << db.lastError().text();
            return;
        }

        QSqlQuery query(db);

        if (query.exec("SELECT date_program_opened FROM Settings;")) {
            if (query.next()) {
                QStringList date_list = query.value(0).toString().split(".");
                if (date_list.size() == 3) {
                    date = QDate(date_list[2].toInt(), date_list[1].toInt(), date_list[0].toInt());
                    if (date != today) {
                        first_todays_opening = true;
                    }
                }
            } else {
                first_todays_opening = true;
            }
        }

        if (first_todays_opening) {
            db.transaction();

            query.exec("DELETE FROM Settings;");

            query.prepare("INSERT INTO Settings (date_program_opened) VALUES (:date);");
            query.bindValue(":date", today.toString("dd.MM.yyyy"));

            if (!query.exec()) {
                qDebug() << "Error add todays date:" << query.lastError().text();
                db.rollback();
            } else {
                db.commit();
            }
        }

        db.close();
    }
    QSqlDatabase::removeDatabase(QSqlDatabase::defaultConnection);
}

















