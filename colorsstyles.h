#ifndef COLORSSTYLES_H
#define COLORSSTYLES_H

#include "modules.h"

QString scrollBarStyle = QString(R"(
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

QString taskFrame_style = QString("QFrame {"
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


QString darkStyle =
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
    "}";


QString lightStyle =
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
    "}";

#endif // COLORSSTYLES_H
















