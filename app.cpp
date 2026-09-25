#include "app.h"

app::app()
{
    mainwindow = new MainWindow();
    dbw = new dbworker();
}

int app::run_app(){

    mainwindow->show();

    mainwindow->setTasks(dbw->getTasks());

    mainwindow->setTodaysOpened(dbw->getTodaysOpened());

    return 0;
}
