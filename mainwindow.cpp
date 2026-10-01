#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    on_btn_theme_clicked();
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
    int tasks_size = tasks.size();
    if (tasks_size != 0){

        QVBoxLayout *vLayout = new QVBoxLayout(ui->scrollArea->widget());
        ui->scrollArea->setFrameShape(QFrame::NoFrame);

        for(int i = 0; i < tasks_size; i++){

            QFrame* taskFrame = new QFrame(ui->scrollArea->widget());
            taskFrame->setFrameShape(QFrame::Box);
            taskFrame->setMinimumHeight(100);

            vLayout->addWidget(taskFrame);
        }

        vLayout->setSpacing(10);
        vLayout->setContentsMargins(10, 10, 10, 10);
        vLayout->addStretch(tasks_size);
    }
}

void MainWindow::setTodaysOpened(bool fl){
    if (!fl){
        qDebug() << "Впервые открывается сегодня!" << endl;
    }
}

void MainWindow::on_btn_theme_clicked()
{


    if (m_isDarkTheme) {
        // --- НАСТРОЙКА ТЕМНОЙ ТЕМЫ ---
        QString darkStyle =
            "#MainWindow {"
            "   background-color: #2b2b2b;" /* Темный фон окна */
            "   border-radius: 10px;"
            "}"
            "QFrame {"
            "   background-color: #202020;"
            "   border:1px solid #3e3e3e;"
            "   border-radius: 10px;"
            "}"
            "QScrollArea {"
            "   background-color: #202020;"
            "   border-radius: 10px;"
            "}"
            "QScrollArea > QWidget > QWidget {"
            "   background-color: #202020;"
            "   border-radius: 10px;"
            "}"
            "#f_tasks{"
            "   background-color: #202020;"
            "   border:1px solid #3e3e3e;"
            "   border-radius: 10px;"
            "}"
            "QLabel {"
            "   color: #ffffff;"
            "   font-family: 'Segoe UI';"
            "   border: none;"
            "}"
            "QPushButton {"
            "   background-color: #3e3e3e;"
            "   color: #ffffff;"
            "   border: 1px solid #555555;"
            "   border-radius: 5px;"
            "   padding: 5px;"
            "}";

        qApp->setStyleSheet(darkStyle);
        //ui->themeButton->setText("Светлая тема");
    }
    else {
        // --- НАСТРОЙКА СВЕТЛОЙ ТЕМЫ ---
        QString lightStyle =
            "#MainWindow {"
            "   background-color: #ffffff;"
            "   border-radius: 10px;"
            "}"
            "QFrame {"
            "   background-color: #ffffff;"
            "   border:1px solid #e8e8e8;"
            "   border-radius: 10px;"
            "}"
            "QScrollArea {"
            "   background-color: #ffffff;"
            "   border-radius: 10px;"
            "}"
            "QScrollArea > QWidget > QWidget {"
            "   background-color: #ffffff;"
            "   border-radius: 10px;"
            "}"
            "#f_tasks{"
            "   background-color: #ffffff;"
            "   border:1px solid #e8e8e8;"
            "   border-radius: 10px;"
            "}"
            "QLabel {"
            "   color: #000000;"
            "   font-family: 'Segoe UI';"
            "   border: none;"
            "}"
            "QPushButton {"
            "   background-color: #ffffff;"
            "   color: #000000;"
            "   border: 1px solid #cccccc;"
            "   border-radius: 5px;"
            "   padding: 5px;"
            "}";

        qApp->setStyleSheet(lightStyle);
        //ui->themeButton->setText("Темная тема");
    }

    // Меняем состояние флага
    m_isDarkTheme = !m_isDarkTheme;
}





























