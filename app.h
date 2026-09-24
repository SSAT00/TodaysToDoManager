#ifndef APP_H
#define APP_H

#include "modules.h"
#include "mainwindow.h"
#include "dbworker.h"

class app
{
private:
    MainWindow* mainwindow;
    dbworker* dbw;

public:
    app();
    int run_app();

};

#endif // APP_H
