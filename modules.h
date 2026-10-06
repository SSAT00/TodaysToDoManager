#ifndef MODULES_H
#define MODULES_H

#include <QDebug>
#include <QString>
#include <QDateTime>
#include <QVector>
#include <QFrame>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QScrollBar>
#include <QPointer>

#include <QMouseEvent>

#include "themehelper.h"

struct task{
    QString title, subtitle;
    int status;
    QDate date;
    QTime start, end;
    int priority;
};

class ClickableFrame : public QFrame {
    Q_OBJECT
public:
    explicit ClickableFrame(const QString &data, QWidget *parent = nullptr)
        : QFrame(parent), m_data(data) {}

signals:
    void clickedWithData(const QString &data);

protected:
    void mousePressEvent(QMouseEvent *event) override {
        if (event->button() == Qt::LeftButton) {
            emit clickedWithData(m_data); // Выстреливаем сигнал с нашей строкой
        }
        QFrame::mousePressEvent(event); // Передаем событие дальше базовому классу
    }
private:
    QString m_data; // Здесь хранится "забинденная" строка
};

#endif // MODULES_H
