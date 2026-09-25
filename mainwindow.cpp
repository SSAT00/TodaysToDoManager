#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setTasks(QVector<task> tasks_){
    tasks = tasks_;
    pastTasksOnWindow();
}

void MainWindow::pastTasksOnWindow(){
    if (tasks.size() != 0){

    }
}

void MainWindow::setTodaysOpened(bool fl){
    if (!fl){
        qDebug() << "Впервые открывается сегодня!" << endl;
    }
}
