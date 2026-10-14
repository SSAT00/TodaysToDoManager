#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "colorsstyles.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setBGImage();

    QDateTime dateTime = QDateTime::currentDateTime();
    QLocale russianLocale(QLocale::Russian);
    QString formattedString = russianLocale.toString(dateTime, "d MMMM (ddd) yyyy");
    ui->l_today->setText(formattedString);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setTasks(QVector<task> tasks_){
    tasks = tasks_;
    setTasksOnWindow();
    QDateTime today_now = QDateTime::currentDateTime();
}

void MainWindow::setTasksOnWindow() {
    QWidget *contentWidget = ui->scrollAreaTasks->widget();
    if (!contentWidget) return;

    if (contentWidget->layout()) {
        QLayout *oldLayout = contentWidget->layout();
        QLayoutItem *item;
        while ((item = oldLayout->takeAt(0)) != nullptr) {
            if (item->widget()) {
                delete item->widget();
            }
            delete item;
        }
        delete oldLayout;
    }

    ui->scrollAreaTasks->setFrameShape(QFrame::NoFrame);

    if (tasks.isEmpty()) return;

    QVBoxLayout *vLayout = new QVBoxLayout(contentWidget);
    vLayout->setSpacing(12);
    vLayout->setContentsMargins(12, 12, 12, 12);

    QString handleColor = m_isDarkTheme ? "rgba(255, 255, 255, 0.35)" : "#8C8C8C";
    QString hoverColor  = m_isDarkTheme ? "rgba(255, 255, 255, 0.60)" : "#595959";
    QString pressColor  = m_isDarkTheme ? "rgba(255, 255, 255, 0.85)" : "#262626";

    ui->scrollAreaTasks->setStyleSheet(scrollBarStyle.arg(handleColor, hoverColor, pressColor));
    ui->scrollAreaTasks->verticalScrollBar()->setStyleSheet(scrollBarStyle.arg(handleColor, hoverColor, pressColor));

    for (int i = 0; i < tasks.size(); ++i) {
        const task &t = tasks[i];

        QFrame *taskFrame = new QFrame(contentWidget);
        taskFrame->setFrameShape(QFrame::StyledPanel);
        taskFrame->setMinimumHeight(130);
        taskFrame->setMaximumHeight(130);
        taskFrame->setObjectName(t.short_title);

        QString statusColor = statusColors[t.status];
        QString statusText = statusTexts[t.status];

        QString priorityText = priorityTexts[t.priority];
        QString priorityColor = priorityColors[t.priority];

        taskFrame->setStyleSheet(taskFrame_style.arg(t.short_title, statusColor));

        QHBoxLayout *cardLayout = new QHBoxLayout(taskFrame);
        cardLayout->setContentsMargins(16, 12, 16, 12);
        cardLayout->setSpacing(12);

        QVBoxLayout *textLayout = new QVBoxLayout();
        textLayout->setSpacing(4);

        QLabel *titleLabel = new QLabel(t.title, taskFrame);
        titleLabel->setStyleSheet("font-size: 18px; font-weight: bold; border: none; background: transparent;");

        QScrollArea *scrollArea = new QScrollArea();
        scrollArea->setWidgetResizable(true);

        QLabel *subtitleLabel = new QLabel(t.subtitle, taskFrame);
        subtitleLabel->setStyleSheet("font-size: 14px; color: #888888; border: none; background: transparent;");
        subtitleLabel->setWordWrap(true);
        subtitleLabel->setAlignment(Qt::AlignTop);

        scrollArea->setWidget(subtitleLabel);

        textLayout->addWidget(titleLabel);
        textLayout->addWidget(scrollArea);

        textLayout->addStretch();

        QVBoxLayout *infoLayout = new QVBoxLayout();
        infoLayout->setSpacing(4);
        infoLayout->setAlignment(Qt::AlignRight | Qt::AlignTop);

        QString timeStr = QString("%1 - %2")
                            .arg(t.start.toString("hh:mm"))
                            .arg(t.end.toString("hh:mm"));
        QLabel *timeLabel = new QLabel(timeStr, taskFrame);
        timeLabel->setStyleSheet("font-size: 14px; font-weight: 500; border: none; background: transparent;");
        timeLabel->setAlignment(Qt::AlignRight);
        timeLabel->setFixedSize(QSize(160, 30));

        QLabel *priorityLabel = new QLabel(QString("Приоритет: %1").arg(priorityText), taskFrame);
        priorityLabel->setStyleSheet(QString("font-size: 13px; color: %1; border: none; background: transparent;").arg(priorityColor));
        priorityLabel->setAlignment(Qt::AlignRight);
        priorityLabel->setFixedSize(QSize(160, 30));

        QVector<QString> btnTexts = {"Начать", "Завершить"};
        QPushButton* btn_action = new QPushButton("");
        btn_action->setFixedSize(QSize(160, 30));
        if (t.status >= 2){
            btn_action->setEnabled(false);
            btn_action->hide();
        }else{
            btn_action->setText(btnTexts[t.status]);
        }
        connect(btn_action, &QPushButton::clicked, this, [=]() {
            btn_change_status_clicked(tasks[i].short_title);
        });

        infoLayout->addWidget(timeLabel);
        infoLayout->addWidget(priorityLabel);
        infoLayout->addWidget(btn_action);

        cardLayout->addLayout(textLayout, 1);
        cardLayout->addLayout(infoLayout, 0);

        vLayout->addWidget(taskFrame);
    }

    vLayout->addStretch();

}

void MainWindow::setNewTask(task t){

    t.short_title = "task_" + QString::number(tasks.size());
    tasks.append(t);
    setTasksOnWindow();

    QScrollBar* vScrollBar = ui->scrollAreaTasks->verticalScrollBar();

    QCoreApplication::processEvents();

    QTimer::singleShot(0, this, [vScrollBar]() {
        vScrollBar->setValue(vScrollBar->maximum());
    });

}

void MainWindow::setTheme(){
    if (m_isDarkTheme) {
        qApp->setStyleSheet(darkStyle);
        ui->btn_theme->setIcon(QIcon("img/sun.png"));
    } else {
        qApp->setStyleSheet(lightStyle);
        ui->btn_theme->setIcon(QIcon("img/moon.png"));
    }
    ThemeHelper::applyThemeToTitleBar(this, m_isDarkTheme);
}

void MainWindow::on_btn_theme_clicked()
{
    m_isDarkTheme = !m_isDarkTheme;
    setTheme();
    emit change_theme(m_isDarkTheme);
}

void MainWindow::setBGImage(){
    QWidget *contentWidget_img = ui->scrollAreaTasks->widget();
    if (contentWidget_img) {

        ui->scrollAreaTasks->setStyleSheet("QScrollArea { border: none; background: transparent; }");
        ui->scrollAreaTasks->viewport()->setStyleSheet("background: transparent;");

        contentWidget_img->setStyleSheet(
            "QWidget#scrollAreaWidgetContents {"
            "   border-radius: 5px;"
            "   border-image: url(img/light_bg.png) 0 0 0 0 stretch stretch;"
            "}"
        );
    }
}

void MainWindow::btn_change_status_clicked(QString short_title){

    QScrollBar* vScrollBar = ui->scrollAreaTasks->verticalScrollBar();
    int current_scroll_value = vScrollBar->value();

    for(int i = 0; i < tasks.size(); i ++){
        if (short_title == tasks[i].short_title){
            tasks[i].status += 1;
            emit status_changed(short_title);
            setTasksOnWindow();
        }
    }

    QCoreApplication::processEvents();

    QTimer::singleShot(0, this, [vScrollBar, current_scroll_value]() {
        vScrollBar->setValue(current_scroll_value);
    });
}


























