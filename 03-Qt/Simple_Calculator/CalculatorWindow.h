/**
 * @file CalculatorWindow.h
 * @author Ziad Mohammed Fathy
 * @brief 
 * @version 0.1
 * @date 2025-04-21
 */

#ifndef _CALCULATOR_WINDOW_H_
#define _CALCULATOR_WINDOW_H_


#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>

class CalculatorWindow : public QWidget {
    Q_OBJECT

    public:
        CalculatorWindow(QWidget* copyParent = nullptr);
    private slots:
        void onButtonClicked();
        void onEqualClicked();
        void onClearClicked();
    private: 
        QLineEdit*   display;
        QGridLayout* Layout;
        QString currentExpression;
        void addButton(const QString &text, int row, int col);
};

#endif