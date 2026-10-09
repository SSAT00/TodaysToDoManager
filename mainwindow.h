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
    QVector<QPushButton*> btns_task_action;

    void setTasksOnWindow();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setTasks(QVector<task>);
    void setNewTask(task);
    void setTheme();
    void setBGImage();
    void setTheme(bool isdark_){m_isDarkTheme = isdark_;}

    bool m_isDarkTheme;

private:
    Ui::MainWindow *ui;


private slots:
    void on_btn_theme_clicked();
    void on_btn_openWindowAddTask_clicked(){emit open_window_add_task();};

signals:
    void change_theme(bool);
    void open_window_add_task();
};

#endif // MAINWINDOW_H
