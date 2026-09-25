#ifndef MODULES_H
#define MODULES_H

#include <QDebug>
#include <QString>
#include <QDateTime>
#include <QVector>

struct task{
    QString title, subtitle;
    int status;
    QDate date;
    QTime start, end;
    int priority;
};

#endif // MODULES_H
