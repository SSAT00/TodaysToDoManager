#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "modules.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QVector<task> tasks;

    void pastTasksOnWindow();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setTasks(QVector<task>);
    void setTodaysOpened(bool);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
