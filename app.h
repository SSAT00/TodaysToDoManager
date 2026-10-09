#ifndef APP_H
#define APP_H

#include <QObject>


#include "mainwindow.h"
#include "dbworker.h"
#include "addtaskwindow.h"

class app : public QObject
{
    Q_OBJECT

private:
    MainWindow* mainwindow;
    dbworker* dbw;
    QPointer<AddTaskWindow> atwindow;

public:
    explicit app(QObject *parent = nullptr);
    ~app() override = default;

    int run_app();

public slots:
    void openWindowAddTask();
};

#endif // APP_H
