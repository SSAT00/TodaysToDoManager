#ifndef ADDTASKWINDOW_H
#define ADDTASKWINDOW_H

#include <QWidget>

#include "modules.h"
#include "themehelper.h"


namespace Ui {
class AddTaskWindow;
}

class AddTaskWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AddTaskWindow(QWidget *parent = nullptr);
    ~AddTaskWindow();

    void setTasks(QVector<QString> t_) {task_titles = t_;}
    void setTheme(bool f){isDark = f;}

private:
    Ui::AddTaskWindow *ui;
    int priority = 1;
    QVector<QString> task_titles;
    bool isDark;

    bool data_is_valid();

private slots:
    void on_btn_create_clicked();
    void on_btn_cancel_clicked(){
        this->close();
    }

    void on_btn_low_clicked();
    void on_btn_mid_clicked();
    void on_btn_high_clicked();
    void on_btn_critical_clicked();

signals:
    void new_task(task);
};

#endif // ADDTASKWINDOW_H
