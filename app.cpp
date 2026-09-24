#include "app.h"

app::app()
{
    mainwindow = new MainWindow();
    dbw = new dbworker();
}

int app::run_app(){

    mainwindow->show();

    return 0;
}
