#include "app.h"

app::app()
{
    mainwindow = new MainWindow();
}

int app::run_app(){

    mainwindow->show();

    return 0;
}

