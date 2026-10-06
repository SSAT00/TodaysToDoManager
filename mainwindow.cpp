#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "colorsstyles.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setBGImage();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setTasks(QVector<task> tasks_){
    tasks = tasks_;
    setTasksOnWindow();
}

void MainWindow::setTasksOnWindow() {
    QWidget *contentWidget = ui->scrollArea->widget();
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

    ui->scrollArea->setFrameShape(QFrame::NoFrame);

    if (tasks.isEmpty()) return;

    QVBoxLayout *vLayout = new QVBoxLayout(contentWidget);
    vLayout->setSpacing(12);
    vLayout->setContentsMargins(12, 12, 12, 12);

    QString handleColor = m_isDarkTheme ? "rgba(255, 255, 255, 0.35)" : "#8C8C8C";
    QString hoverColor  = m_isDarkTheme ? "rgba(255, 255, 255, 0.60)" : "#595959";
    QString pressColor  = m_isDarkTheme ? "rgba(255, 255, 255, 0.85)" : "#262626";

    ui->scrollArea->setStyleSheet(scrollBarStyle.arg(handleColor, hoverColor, pressColor));
    ui->scrollArea->verticalScrollBar()->setStyleSheet(scrollBarStyle.arg(handleColor, hoverColor, pressColor));

    for (int i = 0; i < tasks.size(); ++i) {
        const task &t = tasks[i];

        QFrame *taskFrame = new QFrame(contentWidget);
        taskFrame->setFrameShape(QFrame::StyledPanel);
        taskFrame->setMinimumHeight(90);
        taskFrame->setMaximumHeight(110);

        QString statusColor;
        QString statusText;
        switch (t.status) {
            case 0:
                statusColor = "#8A8A8A";
                statusText = "Не начато";
                break;
            case 1: // Начато
                statusColor = "#E6A23C";
                statusText = "В процессе";
                break;
            case 2: // Завершено
                statusColor = "#67C23A";
                statusText = "Завершено";
                break;
            case 3: // Пропущено
                statusColor = "#F56C6C";
                statusText = "Пропущено";
                break;
            default:
                statusColor = "#8A8A8A";
                statusText = "Неизвестно";
                break;
        }

        QString priorityText;
        QString priorityColor;
        switch (t.priority) {
            case 0: priorityText = "Низкий"; priorityColor = "#909399"; break;
            case 1: priorityText = "Средний"; priorityColor = "#409EFF"; break;
            case 2: priorityText = "Высокий"; priorityColor = "#E6A23C"; break;
            case 3: priorityText = "Критический"; priorityColor = "#F56C6C"; break;
            default: priorityText = "Обычный"; priorityColor = "#909399"; break;
        }

        taskFrame->setStyleSheet(taskFrame_style.arg(statusColor));

        QHBoxLayout *cardLayout = new QHBoxLayout(taskFrame);
        cardLayout->setContentsMargins(16, 12, 16, 12);
        cardLayout->setSpacing(12);

        QVBoxLayout *textLayout = new QVBoxLayout();
        textLayout->setSpacing(4);

        QLabel *titleLabel = new QLabel(t.title, taskFrame);
        titleLabel->setStyleSheet("font-size: 18px; font-weight: bold; border: none; background: transparent;");

        QLabel *subtitleLabel = new QLabel(t.subtitle, taskFrame);
        subtitleLabel->setStyleSheet("font-size: 14px; color: #888888; border: none; background: transparent;");
        subtitleLabel->setWordWrap(true);

        textLayout->addWidget(titleLabel);
        textLayout->addWidget(subtitleLabel);
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

        QLabel *priorityLabel = new QLabel(QString("Приоритет: %1").arg(priorityText), taskFrame);
        priorityLabel->setStyleSheet(QString("font-size: 13px; color: %1; border: none; background: transparent;").arg(priorityColor));
        priorityLabel->setAlignment(Qt::AlignRight);

        QLabel *statusLabel = new QLabel(statusText, taskFrame);
        statusLabel->setStyleSheet(QString(
            "font-size: 13px; font-weight: bold; color: %1; "
            "border: none; background: transparent;"
        ).arg(statusColor));
        statusLabel->setAlignment(Qt::AlignRight);

        infoLayout->addWidget(timeLabel);
        infoLayout->addWidget(priorityLabel);
        infoLayout->addWidget(statusLabel);

        cardLayout->addLayout(textLayout, 1);
        cardLayout->addLayout(infoLayout, 0);

        vLayout->addWidget(taskFrame);
    }

    vLayout->addStretch();

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
    QWidget *contentWidget_img = ui->scrollArea->widget();
    if (contentWidget_img) {

        ui->scrollArea->setStyleSheet("QScrollArea { border: none; background: transparent; }");
        ui->scrollArea->viewport()->setStyleSheet("background: transparent;");

        contentWidget_img->setStyleSheet(
            "QWidget#scrollAreaWidgetContents {"
            "   border-radius: 5px;"
            "   border-image: url(img/light_bg.png) 0 0 0 0 stretch stretch;"
            "}"
        );
    }
}




























