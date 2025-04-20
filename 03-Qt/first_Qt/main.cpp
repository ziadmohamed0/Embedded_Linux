/**
 * @file main.cpp
 * @brief Simple Qt application with QLabel, QLineEdit and message pop-up
 * @author Ziad Mohammed Fathy
 * @date 2025-04-19
 */

#include <iostream>       // Standard C++ I/O
#include <QApplication>   // For QApplication - Qt's main event loop
#include <QLabel>         // For displaying static text (e.g. Name)
#include <QLineEdit>      // For editable text input
#include <QMessageBox>    // For showing message popups
#include <QWidget>        // Base class for all UI objects

/**
 * @class Window
 * @brief Custom Qt window that contains a label, input field, and handles return key event.
 */
class Window : public QWidget {
public:
    /**
     * @brief Constructor to initialize UI components and connect signals.
     * @param copyParent Parent widget (optional).
     */
    Window(QWidget* copyParent = nullptr) : QWidget(copyParent) {
        setFixedSize(500, 250);  ///< Set fixed window size (Width=500, Height=250)

        // Create and position QLabel for "Name"
        name = new QLabel("Name", this);
        name->move(50, 100);

        // Create and position QLineEdit for user input
        name_edit = new QLineEdit(this);
        name_edit->move(100, 100);

        // Connect returnPressed signal from QLineEdit to EnterPressed() slot
        connect(name_edit, &QLineEdit::returnPressed, this, &Window::EnterPressed);
    }

    /**
     * @brief Slot that gets called when user presses Enter in the text field.
     *        It shows a message box with the entered text and prints a welcome message.
     */
    void EnterPressed() {
        QMessageBox msg;
        msg.setText(name_edit->text());  // Set text from QLineEdit
        msg.exec();                      // Show the message box
        std::cout << "Hello, welcome to my Qt UI :)\n";
    }

private:
    QLabel* name;          ///< Label to prompt for name
    QLineEdit* name_edit;  ///< Input field for name
};

/**
 * @brief Main entry point for the Qt application.
 * @param argc Argument count
 * @param argv Argument values
 * @return Application exit status
 */
int main(int argc, char* argv[]) {
    QApplication app(argc, argv);  ///< Initialize Qt application
    Window window;                 ///< Create window object
    window.show();                 ///< Show window on screen
    return app.exec();             ///< Run application loop
}

