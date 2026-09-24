#include "app.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    app *application = new app();
    application->run_app();

    return a.exec();
}
