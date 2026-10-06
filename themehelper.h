#ifndef THEMEHELPER_H
#define THEMEHELPER_H

#include <QWidget>
#include <QGuiApplication>
#include <QStyleHints>

#if defined(Q_OS_WIN)
#include <windows.h>
#include <dwmapi.h>
#pragma comment(lib, "dwmapi.lib")
#endif

class ThemeHelper {
public:
    static void applyThemeToTitleBar(QWidget* window, bool isDark) {
        if (!window) return;

        // 1. Для Qt 6.5+
#if QT_VERSION >= QT_VERSION_CHECK(6, 5, 0)
        QGuiApplication::setStyleHints(isDark ? Qt::ColorScheme::Dark : Qt::ColorScheme::Light);
#endif

        // 2. Для Windows 10/11
#if defined(Q_OS_WIN)
        HWND hwnd = reinterpret_cast<HWND>(window->winId());
        BOOL useDarkMode = isDark ? TRUE : FALSE;
        if (FAILED(DwmSetWindowAttribute(hwnd, 20, &useDarkMode, sizeof(useDarkMode)))) {
            DwmSetWindowAttribute(hwnd, 19, &useDarkMode, sizeof(useDarkMode));
        }
        SetWindowPos(hwnd, nullptr, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_FRAMECHANGED);
#endif
    }
};

#endif // THEMEHELPER_H
