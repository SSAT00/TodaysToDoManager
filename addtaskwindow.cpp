#include "addtaskwindow.h"
#include "ui_addtaskwindow.h"
#include "colorsstyles.h"


AddTaskWindow::AddTaskWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddTaskWindow)
{
    ui->setupUi(this);

    on_btn_low_clicked();
}

AddTaskWindow::~AddTaskWindow()
{
    delete ui;
}

void AddTaskWindow::on_btn_create_clicked(){
    if (data_is_valid()){

        task t;

        t.title = ui->le_title->text();
        t.subtitle = ui->le_subtitle->toPlainText();
        t.status = 0;

        t.date = QDate::currentDate();

        t.start = ui->te_start->time();

        t.end = ui->te_end->time();

        t.priority = priority;

        emit new_task(t);

        this->close();
    }
}

void AddTaskWindow::on_btn_low_clicked(){
    if (priority != 0){
        ui->btn_low->setStyleSheet(btnLowStyleFocus);
        priority = 0;
        ui->btn_mid->setStyleSheet(btnMidStyleNoFocus);
        ui->btn_high->setStyleSheet(btnHighStyleNoFocus);
        ui->btn_critical->setStyleSheet(btnCriticalStyleNoFocus);
    } else ui->btn_low->setStyleSheet(btnLowStyleFocus);
}

void AddTaskWindow::on_btn_mid_clicked(){
    if (priority != 1){
        ui->btn_mid->setStyleSheet(btnMidStyleFocus);
        priority = 1;
        ui->btn_low->setStyleSheet(btnLowStyleNoFocus);
        ui->btn_high->setStyleSheet(btnHighStyleNoFocus);
        ui->btn_critical->setStyleSheet(btnCriticalStyleNoFocus);
    } else ui->btn_mid->setStyleSheet(btnMidStyleFocus);
}

void AddTaskWindow::on_btn_high_clicked(){
    if (priority != 2){
        ui->btn_high->setStyleSheet(btnHighStyleFocus);
        priority = 2;
        ui->btn_low->setStyleSheet(btnLowStyleNoFocus);
        ui->btn_mid->setStyleSheet(btnMidStyleNoFocus);
        ui->btn_critical->setStyleSheet(btnCriticalStyleNoFocus);
    } else ui->btn_high->setStyleSheet(btnHighStyleFocus);
}

void AddTaskWindow::on_btn_critical_clicked(){
    if (priority != 3){
        ui->btn_critical->setStyleSheet(btnCriticalStyleFocus);
        priority = 3;
        ui->btn_low->setStyleSheet(btnLowStyleNoFocus);
        ui->btn_mid->setStyleSheet(btnMidStyleNoFocus);
        ui->btn_high->setStyleSheet(btnHighStyleNoFocus);
    } else ui->btn_critical->setStyleSheet(btnCriticalStyleFocus);
}

bool AddTaskWindow::data_is_valid(){
    QString title = ui->le_title->text();
    if (title == ""){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Уведомление");
        msgBox.setText("Заполните название задачи!");
        msgBox.button(QMessageBox::Ok);

        #ifdef Q_OS_WIN
        ThemeHelper::applyThemeToTitleBar(&msgBox, isDark);
        #endif

        msgBox.exec();

        return false;
    }

    for(int i = 0 ; i < task_titles.size(); i ++){
        if (title == task_titles[i]){
            QMessageBox::information(
                this,
                "Уведомление",
                "Задача с таким названием уже существует!",
                QMessageBox::Ok
            );
            return false;
        }
    }

    QString sub_title = ui->le_subtitle->toPlainText();
    if (sub_title == ""){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Уведомление");
        msgBox.setText("Заполните описание задачи!");
        msgBox.button(QMessageBox::Ok);

        #ifdef Q_OS_WIN
        ThemeHelper::applyThemeToTitleBar(&msgBox, isDark);
        #endif

        msgBox.exec();

        return false;
    }

    QTime start = ui->te_start->time();
    QTime end = ui->te_end->time();
    QTime now = QTime::currentTime();
    if (start < now || end < now || end < start){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Уведомление");
        msgBox.setText("Выбрано не корректное время!");
        msgBox.button(QMessageBox::Ok);

        #ifdef Q_OS_WIN
        ThemeHelper::applyThemeToTitleBar(&msgBox, isDark);
        #endif

        msgBox.exec();

        return false;
    }

    return true;
}

























