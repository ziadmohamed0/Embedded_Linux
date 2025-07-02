/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *btn_mult;
    QPushButton *btn_divid;
    QPushButton *btn_sum;
    QPushButton *btn_sub;
    QLabel *num1;
    QLabel *num2;
    QLineEdit *inNum1;
    QLineEdit *inNum2;
    QLabel *result;
    QLineEdit *outResult;
    QMenuBar *menubar;
    QMenu *menuSimple_Calc;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(436, 202);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        btn_mult = new QPushButton(centralwidget);
        btn_mult->setObjectName(QString::fromUtf8("btn_mult"));
        btn_mult->setGeometry(QRect(40, 30, 89, 25));
        btn_divid = new QPushButton(centralwidget);
        btn_divid->setObjectName(QString::fromUtf8("btn_divid"));
        btn_divid->setGeometry(QRect(40, 60, 89, 25));
        btn_sum = new QPushButton(centralwidget);
        btn_sum->setObjectName(QString::fromUtf8("btn_sum"));
        btn_sum->setGeometry(QRect(40, 90, 89, 25));
        btn_sub = new QPushButton(centralwidget);
        btn_sub->setObjectName(QString::fromUtf8("btn_sub"));
        btn_sub->setGeometry(QRect(40, 120, 89, 25));
        num1 = new QLabel(centralwidget);
        num1->setObjectName(QString::fromUtf8("num1"));
        num1->setGeometry(QRect(160, 40, 91, 17));
        num2 = new QLabel(centralwidget);
        num2->setObjectName(QString::fromUtf8("num2"));
        num2->setGeometry(QRect(160, 70, 121, 17));
        inNum1 = new QLineEdit(centralwidget);
        inNum1->setObjectName(QString::fromUtf8("inNum1"));
        inNum1->setGeometry(QRect(290, 40, 113, 25));
        inNum2 = new QLineEdit(centralwidget);
        inNum2->setObjectName(QString::fromUtf8("inNum2"));
        inNum2->setGeometry(QRect(290, 70, 113, 25));
        result = new QLabel(centralwidget);
        result->setObjectName(QString::fromUtf8("result"));
        result->setGeometry(QRect(160, 100, 51, 17));
        outResult = new QLineEdit(centralwidget);
        outResult->setObjectName(QString::fromUtf8("outResult"));
        outResult->setGeometry(QRect(290, 100, 113, 25));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 436, 22));
        menuSimple_Calc = new QMenu(menubar);
        menuSimple_Calc->setObjectName(QString::fromUtf8("menuSimple_Calc"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuSimple_Calc->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btn_mult->setText(QCoreApplication::translate("MainWindow", "x", nullptr));
        btn_divid->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        btn_sum->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        btn_sub->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        num1->setText(QCoreApplication::translate("MainWindow", "First Number", nullptr));
        num2->setText(QCoreApplication::translate("MainWindow", "Secound Number", nullptr));
        result->setText(QCoreApplication::translate("MainWindow", "Result:", nullptr));
        menuSimple_Calc->setTitle(QCoreApplication::translate("MainWindow", "Simple Calc", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
