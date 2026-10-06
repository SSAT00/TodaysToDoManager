#include "addtaskwindow.h"
#include "ui_addtaskwindow.h"

AddTaskWindow::AddTaskWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddTaskWindow)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
}

AddTaskWindow::~AddTaskWindow()
{
    delete ui;
}




































