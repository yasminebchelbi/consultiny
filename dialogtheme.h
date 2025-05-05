#ifndef DIALOGTHEME_H
#define DIALOGTHEME_H
#include <QString>
inline QString dialogThemeStyle() {
    return R"(
        QDialog { background-color: #263A69; }
        QLabel {
            color: #fff;
            font-weight: bold;
            background: transparent;
        }
        QLineEdit, QDateEdit, QDoubleSpinBox {
            background: #fff; color: #222; border: 1px solid #bbb;
            border-radius: 5px; padding: 3px;
        }
        QPushButton {
            background-color: #f5f5f5; color: #263A69;
            border-radius: 5px; padding: 6px 18px; font-weight: bold;
        }
        QPushButton:disabled { background: #ccc; color: #888; }
        QPushButton:hover { background: #e0e0e0; }
        QDialogButtonBox QPushButton { min-width: 80px; }
        * { background: transparent; }
    )";
}
#endif // DIALOGTHEME_H
