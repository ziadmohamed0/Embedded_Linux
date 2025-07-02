/**
 * @file main.cpp
 * @author Ziad Mohammed Fathy
 * @brief 
 * @version 0.1
 * @date 2025-04-21
 */

#include "CalculatorWindow.h"
#include <QApplication>

int main (int argc, char* argv[]) {
	QApplication app(argc, argv);
    CalculatorWindow window;
    window.show();
	return app.exec();
}
