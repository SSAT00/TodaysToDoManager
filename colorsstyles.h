#ifndef COLORSSTYLES_H
#define COLORSSTYLES_H

#include <QVector>
#include <QString>

inline QVector<QString> statusColors = {"#8A8A8A", "#E6A23C", "#67C23A", "#F56C6C"};
inline QVector<QString> statusTexts = {"Не начато", "Начато", "Завершено", "Пропущено"};

inline QVector<QString> priorityColors = {"#909399", "#409EFF", "#E6A23C", "#F56C6C"};
inline QVector<QString> priorityTexts = {"Низкий", "Средний", "Высокий", "Критический"};


inline QString btnLowStyleNoFocus = "#btn_low{"
    "   background-color: rgba(144, 147, 153, 0.3);"
    "   border: 1px solid rgba(144, 147, 153, 0.3);"
    "   border-radius: 5px;"
    "}"
    "#btn_low::hover{"
    "   background-color: rgba(144, 147, 153, 0.5);"
    "   border: 1px solid rgba(144, 147, 153, 0.5);"
    "   border-radius: 5px;"
    "}";

inline QString btnLowStyleFocus = "#btn_low{"
    "   background-color: rgba(144, 147, 153, 0.3);"
    "   border: 1px solid rgba(144, 147, 153, 0.7);"
    "   border-radius: 5px;"
    "}"
    "#btn_low::hover{"
    "   background-color: rgba(144, 147, 153, 0.5);"
    "   border: 1px solid rgba(144, 147, 153, 0.7);"
    "   border-radius: 5px;"
    "}";

inline QString btnMidStyleNoFocus = "#btn_mid{"
    "   background-color: rgba(64, 158, 255, 0.3);"
    "   border: 1px solid rgba(64, 158, 255, 0.3);"
    "   border-radius: 5px;"
    "}"
    "#btn_mid::hover{"
    "   background-color: rgba(64, 158, 255, 0.5);"
    "   border: 1px solid rgba(64, 158, 255, 0.5);"
    "   border-radius: 5px;"
    "}";

inline QString btnMidStyleFocus = "#btn_mid{"
    "   background-color: rgba(64, 158, 255, 0.3);"
    "   border: 1px solid rgba(64, 158, 255, 0.7);"
    "   border-radius: 5px;"
    "}"
    "#btn_mid::hover{"
    "   background-color: rgba(64, 158, 255, 0.5);"
    "   border: 1px solid rgba(64, 158, 255, 0.7);"
    "   border-radius: 5px;"
    "}";

inline QString btnHighStyleNoFocus = "#btn_high{"
    "   background-color: rgba(230, 162, 60, 0.3);"
    "   border: 1px solid rgba(230, 162, 60, 0.3);"
    "   border-radius: 5px;"
    "}"
    "#btn_high::hover{"
    "   background-color: rgba(230, 162, 60, 0.5);"
    "   border: 1px solid rgba(230, 162, 60, 0.5);"
    "   border-radius: 5px;"
    "}";

inline QString btnHighStyleFocus = "#btn_high{"
    "   background-color: rgba(230, 162, 60, 0.3);"
    "   border: 1px solid rgba(230, 162, 60, 0.7);"
    "   border-radius: 5px;"
    "}"
    "#btn_high::hover{"
    "   background-color: rgba(230, 162, 60, 0.5);"
    "   border: 1px solid rgba(230, 162, 60, 0.7);"
    "   border-radius: 5px;"
    "}";

inline QString btnCriticalStyleNoFocus = "#btn_critical{"
    "   background-color: rgba(245, 108, 108, 0.3);"
    "   border: 1px solid rgba(245, 108, 108, 0.3);"
    "   border-radius: 5px;"
    "}"
    "#btn_critical::hover{"
    "   background-color: rgba(245, 108, 108, 0.5);"
    "   border: 1px solid rgba(245, 108, 108, 0.5);"
    "   border-radius: 5px;"
    "}";

inline QString btnCriticalStyleFocus = "#btn_critical{"
    "   background-color: rgba(245, 108, 108, 0.3);"
    "   border: 1px solid rgba(245, 108, 108, 0.7);"
    "   border-radius: 5px;"
    "}"
    "#btn_critical::hover{"
    "   background-color: rgba(245, 108, 108, 0.5);"
    "   border: 1px solid rgba(245, 108, 108, 0.7);"
    "   border-radius: 5px;"
    "}";


inline QString scrollBarStyle = QString(R"(
    QScrollArea {
        border: none;
        background: transparent;
    }

    QScrollArea > QWidget > QWidget {
        background: transparent;
    }

    QScrollBar:vertical {
        border: none;
        background-color: transparent;
        width: 10px;
        margin: 0px 2px 0px 2px;
    }

    QScrollBar::handle:vertical {
        background-color: %1;
        border-radius: 3px;
        min-height: 24px;
    }

    QScrollBar::handle:vertical:hover {
        background-color: %2;
    }

    QScrollBar::handle:vertical:pressed {
        background-color: %3;
    }

    QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {
        border: none;
        background: none;
        height: 0px;
    }

    QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {
        border: none;
        background: none;
    }
)");

inline QString taskFrame_style = QString("QFrame {"
            "   background-color: rgba(255, 255, 255, 0.04);"
            "   border: 1px solid rgba(128, 128, 128, 0.2);"
            "   border-left: 5px solid %1;"
            "   border-radius: 8px;"
            "}"
            "QFrame:hover {"
            "   border-color: rgba(128, 128, 128, 0.4);"
            "   border-left: 5px solid %1;"
            "   background-color: rgba(255, 255, 255, 0.06);"
            "}");


inline QString darkStyle =
    "#MainWindow {"
    "   background-color: #2b2b2b;"
    "   border-radius: 10px;"
    "}"
    "#AddTaskWindow {"
    "   background-color: #2b2b2b;"
    "   border-radius: 10px;"
    "}"
    "QLineEdit {"
    "   background-color: #2b2b2b;"
    "   border-radius: 10px;"
    "   border: 1px solid #3e3e3e;"
    "   color: #fff;"
    "   padding: 5px;"
    "   font-weight: 700;"
    "}"
    "QTextEdit {"
    "   background-color: #2b2b2b;"
    "   border-radius: 10px;"
    "   border: 1px solid #3e3e3e;"
    "   color: #fff;"
    "   padding: 5px;"
    "}"
    "QFrame {"
    "   background-color: #202020;"
    "   border:1px solid #3e3e3e;"
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
    "   background-color: transparent;"
    "}"
    "QPushButton {"
    "   background-color: #3e3e3e;"
    "   color: #ffffff;"
    "   border: 1px solid #555555;"
    "   border-radius: 5px;"
    "   padding: 5px;"
    "}"
    "QTimeEdit {"
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
    "}"
    "QMessageBox {"
    "    background-color: #2b2b2b;"
    "    color: #ffffff;"
    "}"
    "QMessageBox QLabel {"
    "    color: #ffffff;"
    "}"
    "QMessageBox QPushButton {"
    "    background-color: #3c3f41;"
    "    color: #ffffff;"
    "    border: 1px solid #555555;"
    "    border-radius: 4px;"
    "    padding: 6px 16px;"
    "    min-width: 70px;"
    "}"
    "QMessageBox QPushButton:hover {"
    "    background-color: #484b4d;"
    "    border-color: #666666;"
    "}"
    "QMessageBox QPushButton:pressed {"
    "    background-color: #55585a;"
    "}";



inline QString lightStyle =
    "#MainWindow {"
    "   background-color: #ffffff;"
    "   border-radius: 10px;"
    "}"
    "#AddTaskWindow {"
    "   background-color: #ffffff;"
    "   border-radius: 10px;"
    "}"
    "QLineEdit {"
    "   background-color: #ffffff;"
    "   border-radius: 10px;"
    "   border: 1px solid #e8e8e8;"
    "   color: #000;"
    "   padding: 5px;"
    "   font-weight: 700;"
    "}"
    "QTextEdit {"
    "   background-color: #ffffff;"
    "   border-radius: 10px;"
    "   border: 1px solid #e8e8e8;"
    "   color: #000;"
    "   padding: 5px;"
    "}"
    "QFrame {"
    "   background-color: #ffffff;"
    "   border:1px solid #e8e8e8;"
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
    "   background-color: transparent;"
    "}"
    "QPushButton {"
    "   background-color: #ffffff;"
    "   color: #000000;"
    "   border: 1px solid #cccccc;"
    "   border-radius: 5px;"
    "   padding: 5px;"
    "}"
    "QTimeEdit {"
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
    "}"
    "QMessageBox {"
    "    background-color: #f5f5f7;"
    "    color: #1d1d1f;"
    "}"
    "QMessageBox QLabel {"
    "    color: #1d1d1f;"
    "}"
    "QMessageBox QPushButton {"
    "    background-color: #ffffff;"
    "    color: #1d1d1f;"
    "    border: 1px solid #d2d2d7;"
    "    border-radius: 4px;"
    "    padding: 6px 16px;"
    "    min-width: 70px;"
    "}"
    "QMessageBox QPushButton:hover {"
    "    background-color: #e8e8ed;"
    "    border-color: #b1b1b5;"
    "}"
    "QMessageBox QPushButton:pressed {"
    "    background-color: #d8d8dc;"
    "}";

#endif // COLORSSTYLES_H
















