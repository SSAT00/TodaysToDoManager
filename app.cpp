#include "app.h"

app::app(QObject *parent)
    : QObject(parent), mainwindow(nullptr), dbw(nullptr), atwindow(nullptr)
{
    dbw = new dbworker();

    mainwindow = new MainWindow();

    QObject::connect(mainwindow, &MainWindow::change_theme, dbw, &dbworker::setTheme);
    QObject::connect(mainwindow, &MainWindow::open_window_add_task, this, &app::openWindowAddTask);
}

int app::run_app(){

    mainwindow->setTheme(dbw->getTheme());
    mainwindow->setTheme();
    mainwindow->show();
    mainwindow->setTasks(dbw->getTasks());

    return 0;
}

void app::openWindowAddTask(){
    if (atwindow) {
        atwindow->close();
    }

    atwindow = new AddTaskWindow(mainwindow);

    atwindow->setAttribute(Qt::WA_DeleteOnClose);

    atwindow->setWindowFlags(Qt::Window);
    atwindow->setWindowModality(Qt::WindowModal);

    atwindow->show();
    atwindow->raise();
    atwindow->activateWindow();

    ThemeHelper::applyThemeToTitleBar(atwindow, mainwindow->m_isDarkTheme);
}
