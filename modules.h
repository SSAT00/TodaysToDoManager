#ifndef MODULES_H
#define MODULES_H

#include <QDebug>
#include <QString>
#include <QDateTime>
#incldue <QVector>

struct task{
    QString tatle, subtitle;
    int status;
    QDate date;
    QTime start, end;
};

#endif // MODULES_H
