#include "dbworker.h"

dbworker::dbworker(QObject *parent)
    : QObject(parent), first_todays_opening(false)
{
    first_todays_opening = false;
    readSettings();
    readTasks();
}

void dbworker::readTasks(){

    if (first_todays_opening){

        {
            QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
            db.setDatabaseName("tasks.db");

            if (!db.open()) {
                qDebug() << "Ошибка при открытии базы данных с задачами: " << db.lastError().text();
                return;
            }

            QSqlQuery query(db);

            if (!query.exec("DELETE FROM Task;")){
                qDebug() << "Ошибка очистки базы данных" << endl;
            }

            query.clear();
            tasks.clear();
        }

        QSqlDatabase::removeDatabase(QSqlDatabase::defaultConnection);

    } else {

        QVector<int> indexes_missed_tasks;
        int i = 0;

        {
            QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
            db.setDatabaseName("tasks.db");

            if (!db.open()) {
                qDebug() << "Ошибка при открытии базы данных с задачами: " << db.lastError().text();
                return;
            }

            QSqlQuery query(db);

            QTime now_time = QTime::currentTime();

            if (query.exec("SELECT title, subtitle, status, date, start, end, priority FROM Task;")){
                while (query.next()) {
                    task t;

                    t.short_title = "task_" + QString::number(i);

                    t.title = query.value(0).toString();
                    t.subtitle = query.value(1).toString();
                    t.status = query.value(2).toInt();

                    QStringList date_list = query.value(3).toString().split(".");
                    t.date = QDate(date_list[0].toInt(), date_list[1].toInt(), date_list[2].toInt());

                    QStringList time_start_list = query.value(4).toString().split(":");
                    t.start = QTime(time_start_list[0].toInt(), time_start_list[1].toInt(), 0);

                    QStringList time_end_list = query.value(5).toString().split(":");
                    t.end = QTime(time_end_list[0].toInt(), time_end_list[1].toInt(), 0);

                    if (t.end < now_time && t.status != 2){
                        t.status = 3;
                        indexes_missed_tasks.append(i);
                    }

                    t.priority = query.value(6).toInt();

                    i++;

                    tasks.append(t);
                }
            }

            query.clear();
        }

        QSqlDatabase::removeDatabase(QSqlDatabase::defaultConnection);

        if (indexes_missed_tasks.size() > 0){

            {
                QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
                db.setDatabaseName("tasks.db");

                if (!db.open()) {
                    qDebug() << "Ошибка при открытии базы данных с задачами: " << db.lastError().text();
                    return;
                }

                QSqlQuery query(db);

                for(int i = 0; i < indexes_missed_tasks.size(); i++){

                    QString title = tasks[indexes_missed_tasks[i]].title;

                    query.prepare("UPDATE Task SET status = 3 WHERE title = :title;");
                    query.bindValue(":title", title);

                    if (!query.exec()){
                        qDebug() << "Ошибка перезаписи статуса пропущенной задачи!" << endl;
                    }
                }

                query.clear();
            }

            QSqlDatabase::removeDatabase(QSqlDatabase::defaultConnection);
        }

    }
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

        if (query.exec("SELECT date_program_opened, isdark FROM Settings;")) {
            if (query.next()) {
                QStringList date_list = query.value(0).toString().split(".");
                isdark = query.value(1).toBool();
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

            query.prepare("UPDATE Settings SET date_program_opened = :date;");
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


void dbworker::setTheme(bool isDark){
    {
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("tasks.db");

        if (!db.open()) {
            qDebug() << "Ошибка при открытии базы данных с задачами:" << db.lastError().text();
            return;
        }

        QSqlQuery query(db);

        query.prepare("UPDATE Settings SET isdark = :isdark;");
        query.bindValue(":isdark", isDark);

        if (!query.exec()){
            qDebug() << "Ошибка обновления темы в базе данных" << endl;
        }

        db.close();
    }
    QSqlDatabase::removeDatabase(QSqlDatabase::defaultConnection);
}


void dbworker::setNewTask(task t){
    {
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("tasks.db");

        if (!db.open()) {
            qDebug() << "Ошибка при открытии базы данных с задачами:" << db.lastError().text();
            return;
        }

        db.transaction();

        QSqlQuery query(db);

        query.prepare("INSERT INTO Task (title, subtitle, status, date, start, end, priority) VALUES (:title, :subtitle, :status, :date, :start, :end, :priority);");
        query.bindValue(":title", t.title);
        query.bindValue(":subtitle", t.subtitle);
        query.bindValue(":status", t.status);
        query.bindValue(":date", t.date.toString("dd.MM.yyyy"));
        query.bindValue(":start", t.start.toString("hh:mm"));
        query.bindValue(":end", t.end.toString("hh:mm"));
        query.bindValue(":priority", t.priority);


        if (!query.exec()){
            qDebug() << "Ошибка добавления новой задачи." << endl;
        }

        db.commit();

        db.close();
    }
    QSqlDatabase::removeDatabase(QSqlDatabase::defaultConnection);
    tasks.append(t);
}

void dbworker::setNewStatus(QString short_title){
    for(int i = 0 ; i < tasks.size(); i++){
        if (tasks[i].short_title == short_title){
            {
                QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
                db.setDatabaseName("tasks.db");

                if (!db.open()) {
                    qDebug() << "Ошибка при открытии базы данных с задачами:" << db.lastError().text();
                    return;
                }

                db.transaction();

                QSqlQuery query(db);

                tasks[i].status += 1;

                query.prepare("UPDATE Task SET status = :status WHERE title = :title;");
                query.bindValue(":status", tasks[i].status);
                query.bindValue(":title", tasks[i].title);

                if (!query.exec()){
                    qDebug() << "Ошибка обновления статуса." << endl;
                }

                db.commit();

                db.close();
            }

            QSqlDatabase::removeDatabase(QSqlDatabase::defaultConnection);
        }
    }
}

































