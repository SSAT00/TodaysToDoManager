#include "app.h"

app::app(QObject *parent)
    : QObject(parent), mainwindow(nullptr), dbw(nullptr), atwindow(nullptr)
{
    dbw = new dbworker();

    mainwindow = new MainWindow();

    QObject::connect(mainwindow, &MainWindow::change_theme, dbw, &dbworker::setTheme);
    QObject::connect(mainwindow, &MainWindow::open_window_add_task, this, &app::openWindowAddTask);
    QObject::connect(mainwindow, &MainWindow::status_changed, dbw, &dbworker::setNewStatus);
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

    QVector<task> tasks_ = dbw->getTasks();
    QVector<QString> tt;
    for(int i = 0; i < tasks_.size(); i++){
        tt.append(tasks_[i].title);
    }
    atwindow->setTasks(tt);

    ThemeHelper::applyThemeToTitleBar(atwindow, mainwindow->m_isDarkTheme);
    atwindow->setTheme(mainwindow->m_isDarkTheme);

    QObject::connect(atwindow, &AddTaskWindow::new_task, dbw, &dbworker::setNewTask);
    QObject::connect(atwindow, &AddTaskWindow::new_task, mainwindow, &MainWindow::setNewTask);
}
















