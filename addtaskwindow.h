#ifndef ADDTASKWINDOW_H
#define ADDTASKWINDOW_H

#include <QWidget>

namespace Ui {
class AddTaskWindow;
}

class AddTaskWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AddTaskWindow(QWidget *parent = nullptr);
    ~AddTaskWindow();

private:
    Ui::AddTaskWindow *ui;
};

#endif // ADDTASKWINDOW_H
