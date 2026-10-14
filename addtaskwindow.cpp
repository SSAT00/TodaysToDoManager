#include "addtaskwindow.h"
#include "ui_addtaskwindow.h"
#include "colorsstyles.h"


AddTaskWindow::AddTaskWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddTaskWindow)
{
    ui->setupUi(this);

    on_btn_low_clicked();

    set_times();

    title_error = false;
    ui->l_error->hide();

    QObject::connect(ui->le_title, &QLineEdit::textChanged, this, &AddTaskWindow::title_changed);
    QObject::connect(ui->le_subtitle, &QTextEdit::textChanged, this, &AddTaskWindow::subtitle_changed);
    QObject::connect(ui->te_start, &QTimeEdit::timeChanged, this, &AddTaskWindow::start_time_changed);
    QObject::connect(ui->te_end, &QTimeEdit::timeChanged, this, &AddTaskWindow::end_time_changed);
}

AddTaskWindow::~AddTaskWindow()
{
    delete ui;
}

void AddTaskWindow::set_times(){
    QTime now = QTime::currentTime();
    QTime start = QTime(now.hour()+1, 0);
    QTime end = start.addSecs(3600);

    ui->te_end->setTime(end);
    ui->te_start->setTime(start);
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

void AddTaskWindow::title_changed(){
    if (title_error){
        title_error = false;
        ui->l_error->hide();
        if (isDark) ui->le_title->setStyleSheet("QLineEdit {"
                                                "   background-color: #2b2b2b;"
                                                "   border-radius: 10px;"
                                                "   border: 1px solid #3e3e3e;"
                                                "   color: #fff;"
                                                "   padding: 5px;"
                                                "   font-weight: 700;"
                                                "}"
                                                "QLineEdit::focus{"
                                                "   border-color: #409eff;"
                                                "}");
        else ui->le_title->setStyleSheet("QLineEdit {"
                                         "   background-color: #ffffff;"
                                         "   border-radius: 10px;"
                                         "   border: 1px solid #e8e8e8;"
                                         "   color: #000;"
                                         "   padding: 5px;"
                                         "   font-weight: 700;"
                                         "}"
                                         "QLineEdit::focus{"
                                         "   border-color: #409eff;"
                                         "}");
    }
}

void AddTaskWindow::subtitle_changed(){
    if (subtitle_error){
        subtitle_error = false;
        ui->l_error->hide();
        if (isDark) ui->le_subtitle->setStyleSheet("QTextEdit {"
                                                   "   background-color: #2b2b2b;"
                                                   "   border-radius: 10px;"
                                                   "   border: 1px solid #3e3e3e;"
                                                   "   color: #fff;"
                                                   "   padding: 5px;"
                                                   "}"
                                                   "QTextEdit::focus{"
                                                   "   border-color: #409eff;"
                                                   "}");
        else ui->le_subtitle->setStyleSheet("QTextEdit {"
                                            "   background-color: #ffffff;"
                                            "   border-radius: 10px;"
                                            "   border: 1px solid #e8e8e8;"
                                            "   color: #000;"
                                            "   padding: 5px;"
                                            "}"
                                            "QTextEdit::focus{"
                                            "   border-color: #409eff;"
                                            "}");
    }
}

void AddTaskWindow::start_time_changed(){
    if (start_error){
        start_error = false;
        ui->l_error->hide();
        if (isDark) ui->te_start->setStyleSheet("QTimeEdit {"
                                                "    background-color: transparent;"
                                                "    border: 1px solid #555555;"
                                                "    border-radius: 6px;"
                                                "    padding: 4px 28px 4px 8px;"
                                                "    color: #fff;"
                                                "    font-size: 13px;"
                                                "}"
                                                "QTimeEdit:hover {"
                                                "    border-color: #65676C;"
                                                "}"
                                                "QTimeEdit:focus {"
                                                "    border-color: #409eff;"
                                                "}"
                                                "QTimeEdit::up-button {"
                                                "    subcontrol-origin: padding;"
                                                "    subcontrol-position: top right;"
                                                "    width: 20px;"
                                                "    height: 10px;"
                                                "    border: none;"
                                                "    background: transparent;"
                                                "    margin-top: 2px;"
                                                "    margin-right: 4px;"
                                                "}"
                                                "QTimeEdit::up-arrow {"
                                                "    image: url(img/up_arrow.svg);"
                                                "    width: 10px;"
                                                "    height: 10px;"
                                                "}"
                                                "QTimeEdit::down-button {"
                                                "    subcontrol-origin: padding;"
                                                "    subcontrol-position: bottom right;"
                                                "    width: 20px;"
                                                "    height: 10px;"
                                                "    border: none;"
                                                "    background: transparent;"
                                                "    margin-bottom: 2px;"
                                                "    margin-right: 4px;"
                                                "}"
                                                "QTimeEdit::down-arrow {"
                                                "    image: url(img/down_arrow.svg);"
                                                "    width: 10px;"
                                                "    height: 10px;"
                                                "}"
                                                "QTimeEdit::up-button:hover, QTimeEdit::down-button:hover {"
                                                "    background-color: #f2f6fc;"
                                                "    border-radius: 3px;"
                                                "}");
        else ui->te_start->setStyleSheet("QTimeEdit {"
                                         "    background-color: #ffffff;"
                                         "    border: 1px solid #dcdfe6;"
                                         "    border-radius: 6px;"
                                         "    padding: 4px 28px 4px 8px;"
                                         "    color: #2c3e50;"
                                         "    font-size: 13px;"
                                         "}"
                                         "QTimeEdit:hover {"
                                         "    border-color: #c0c4cc;"
                                         "}"
                                         "QTimeEdit:focus {"
                                         "    border-color: #409eff;"
                                         "}"
                                         "QTimeEdit::up-button {"
                                         "    subcontrol-origin: padding;"
                                         "    subcontrol-position: top right;"
                                         "    width: 20px;"
                                         "    height: 10px;"
                                         "    border: none;"
                                         "    background: transparent;"
                                         "    margin-top: 2px;"
                                         "    margin-right: 4px;"
                                         "}"
                                         "QTimeEdit::up-arrow {"
                                         "    image: url(img/up_arrow.svg);"
                                         "    width: 10px;"
                                         "    height: 10px;"
                                         "}"
                                         "QTimeEdit::down-button {"
                                         "    subcontrol-origin: padding;"
                                         "    subcontrol-position: bottom right;"
                                         "    width: 20px;"
                                         "    height: 10px;"
                                         "    border: none;"
                                         "    background: transparent;"
                                         "    margin-bottom: 2px;"
                                         "    margin-right: 4px;"
                                         "}"
                                         "QTimeEdit::down-arrow {"
                                         "    image: url(img/down_arrow.svg);"
                                         "    width: 10px;"
                                         "    height: 10px;"
                                         "}"
                                         "QTimeEdit::up-button:hover, QTimeEdit::down-button:hover {"
                                         "    background-color: #f2f6fc;"
                                         "    border-radius: 3px;"
                                         "}");
    }
}

void AddTaskWindow::end_time_changed(){
    if (end_error){
        end_error = false;
        ui->l_error->hide();
        if (isDark) ui->te_end->setStyleSheet("QTimeEdit {"
                                                "    background-color: transparent;"
                                                "    border: 1px solid #555555;"
                                                "    border-radius: 6px;"
                                                "    padding: 4px 28px 4px 8px;"
                                                "    color: #fff;"
                                                "    font-size: 13px;"
                                                "}"
                                                "QTimeEdit:hover {"
                                                "    border-color: #65676C;"
                                                "}"
                                                "QTimeEdit:focus {"
                                                "    border-color: #409eff;"
                                                "}"
                                                "QTimeEdit::up-button {"
                                                "    subcontrol-origin: padding;"
                                                "    subcontrol-position: top right;"
                                                "    width: 20px;"
                                                "    height: 10px;"
                                                "    border: none;"
                                                "    background: transparent;"
                                                "    margin-top: 2px;"
                                                "    margin-right: 4px;"
                                                "}"
                                                "QTimeEdit::up-arrow {"
                                                "    image: url(img/up_arrow.svg);"
                                                "    width: 10px;"
                                                "    height: 10px;"
                                                "}"
                                                "QTimeEdit::down-button {"
                                                "    subcontrol-origin: padding;"
                                                "    subcontrol-position: bottom right;"
                                                "    width: 20px;"
                                                "    height: 10px;"
                                                "    border: none;"
                                                "    background: transparent;"
                                                "    margin-bottom: 2px;"
                                                "    margin-right: 4px;"
                                                "}"
                                                "QTimeEdit::down-arrow {"
                                                "    image: url(img/down_arrow.svg);"
                                                "    width: 10px;"
                                                "    height: 10px;"
                                                "}"
                                                "QTimeEdit::up-button:hover, QTimeEdit::down-button:hover {"
                                                "    background-color: #f2f6fc;"
                                                "    border-radius: 3px;"
                                                "}");
        else ui->te_end->setStyleSheet("QTimeEdit {"
                                         "    background-color: #ffffff;"
                                         "    border: 1px solid #dcdfe6;"
                                         "    border-radius: 6px;"
                                         "    padding: 4px 28px 4px 8px;"
                                         "    color: #2c3e50;"
                                         "    font-size: 13px;"
                                         "}"
                                         "QTimeEdit:hover {"
                                         "    border-color: #c0c4cc;"
                                         "}"
                                         "QTimeEdit:focus {"
                                         "    border-color: #409eff;"
                                         "}"
                                         "QTimeEdit::up-button {"
                                         "    subcontrol-origin: padding;"
                                         "    subcontrol-position: top right;"
                                         "    width: 20px;"
                                         "    height: 10px;"
                                         "    border: none;"
                                         "    background: transparent;"
                                         "    margin-top: 2px;"
                                         "    margin-right: 4px;"
                                         "}"
                                         "QTimeEdit::up-arrow {"
                                         "    image: url(img/up_arrow.svg);"
                                         "    width: 10px;"
                                         "    height: 10px;"
                                         "}"
                                         "QTimeEdit::down-button {"
                                         "    subcontrol-origin: padding;"
                                         "    subcontrol-position: bottom right;"
                                         "    width: 20px;"
                                         "    height: 10px;"
                                         "    border: none;"
                                         "    background: transparent;"
                                         "    margin-bottom: 2px;"
                                         "    margin-right: 4px;"
                                         "}"
                                         "QTimeEdit::down-arrow {"
                                         "    image: url(img/down_arrow.svg);"
                                         "    width: 10px;"
                                         "    height: 10px;"
                                         "}"
                                         "QTimeEdit::up-button:hover, QTimeEdit::down-button:hover {"
                                         "    background-color: #f2f6fc;"
                                         "    border-radius: 3px;"
                                         "}");
    }
}


bool AddTaskWindow::data_is_valid(){
    QString title = ui->le_title->text();
    if (title == ""){
        ui->l_error->setText("Заполните название задачи!");
        ui->l_error->show();
        ui->l_error->setStyleSheet("color: #FF9292;");
        ui->le_title->setStyleSheet("border-color: #FF9292;");
        title_error = true;
        ui->le_title->setFocus();

        return false;
    }

    for(int i = 0 ; i < task_titles.size(); i ++){
        if (title == task_titles[i]){
            ui->l_error->setText("Задача с таким названием уже существует!");
            ui->l_error->show();
            ui->l_error->setStyleSheet("color: #FF9292;");
            ui->le_title->setStyleSheet("border-color: #FF9292;");
            title_error = true;
            ui->le_title->setFocus();
            return false;
        }
    }

    QString sub_title = ui->le_subtitle->toPlainText();
    if (sub_title == ""){
        ui->l_error->setText("Заполните описание задачи!");
        ui->l_error->show();
        ui->l_error->setStyleSheet("color: #FF9292;");
        ui->le_subtitle->setStyleSheet("border-color: #FF9292;");
        subtitle_error = true;
        ui->le_subtitle->setFocus();

        return false;
    }

    QTime start = ui->te_start->time();
    QTime end = ui->te_end->time();
    QTime now = QTime::currentTime();

    if(start < now){
        ui->l_error->setText("Время начала не должно быть раньше текущего!");
        ui->l_error->show();
        ui->l_error->setStyleSheet("color: #FF9292;");
        ui->te_start->setStyleSheet("border-color: #FF9292;");
        start_error = true;
        ui->te_start->setFocus();

        return false;
    }

    if (end < now){
        ui->l_error->setText("Время завершения не должно быть раньше текущего!");
        ui->l_error->show();
        ui->l_error->setStyleSheet("color: #FF9292;");
        ui->te_end->setStyleSheet("border-color: #FF9292;");
        end_error = true;
        ui->te_end->setFocus();

        return false;
    }

    if (end < now){
        ui->l_error->setText("Завершение должно быть позже начала!");
        ui->l_error->show();
        ui->l_error->setStyleSheet("color: #FF9292;");
        ui->te_end->setStyleSheet("border-color: #FF9292;");
        end_error = true;
        ui->te_end->setFocus();

        return false;
    }
    return true;
}

























