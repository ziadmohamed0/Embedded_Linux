/**
 * @file CalculatorWindow.cpp
 * @author Ziad Mohammed Fathy
 * @brief 
 * @version 0.1
 * @date 2025-04-21
 */

#include "CalculatorWindow.h"

CalculatorWindow::CalculatorWindow(QWidget* copyParent) 
                                    : QWidget(copyParent) {
    this->setWindowTitle("Simple Calculator");
    this->setFixedSize(400, 400);

    display = new QLineEdit(this);
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);
    display->setFixedHeight(40);
    
    Layout = new QGridLayout(this);
    Layout->addWidget(display, 0, 0, 1, 4);

    QStringList buttons = {
        "7", "8", "9", "/",
        "4", "5", "6", "*",
        "1", "2", "3", "-",
        "0", "C", "=", "+"
    };

    int row = 1, col = 0;
    for (const QString &text : buttons) {
        addButton(text, row, col);
        col++;
        if (col == 4) {
            row++;
            col = 0;
        }
    }
}
