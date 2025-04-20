/**
 * @file login_window.cpp
 * @brief Qt Login window with username and password fields, and login/cancel buttons.
 * @author Ziad Mohammed Fathy
 * @date 2025-04-19
 */

#include <iostream>
#include <QApplication>
#include <QLabel>
#include <QMessageBox>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QWidget>

/**
 * @class Window
 * @brief A simple login form window using Qt Widgets
 */
class Window : public QWidget {
public:
    /**
     * @brief Constructor initializes the login form UI
     * @param copyParent Pointer to the parent widget (optional)
     */
    Window(QWidget* copyParent = nullptr) : QWidget(copyParent) {
        setWindowTitle("Login");
        setFixedSize(500, 250);

        mainLayout = new QVBoxLayout();
        setLayout(mainLayout);

        // Username Row
        raw_1_Layout = new QHBoxLayout();
        raw_1_Layout->setSpacing(50);
        usrname_label = new QLabel("Username:");
        usrname_box = new QLineEdit();
        raw_1_Layout->addWidget(usrname_label);
        raw_1_Layout->addWidget(usrname_box);
        mainLayout->addLayout(raw_1_Layout);

        // Password Row
        raw_2_Layout = new QHBoxLayout();
        raw_2_Layout->setSpacing(50);
        password_label = new QLabel("Password:");
        password_box = new QLineEdit();
        password_box->setEchoMode(QLineEdit::Password);  // Hide password input
        raw_2_Layout->addWidget(password_label);
        raw_2_Layout->addWidget(password_box);
        mainLayout->addLayout(raw_2_Layout);

        // Buttons Row
        raw_3_Layout = new QHBoxLayout();
        raw_3_Layout->addStretch();
        login_btn = new QPushButton("Login");
        cancel_btn = new QPushButton("Cancel");
        raw_3_Layout->addWidget(login_btn);
        raw_3_Layout->addWidget(cancel_btn);
        mainLayout->addLayout(raw_3_Layout);

        // Connect button signals to slots
        connect(login_btn, &QPushButton::clicked, this, &Window::EnterLogin);
        connect(cancel_btn, &QPushButton::clicked, this, &Window::EnterCancel);
    }

    /**
     * @brief Slot executed when the login button is pressed.
     */
    void EnterLogin() {
        std::string username = usrname_box->text().toStdString();

        // Disable input fields
        usrname_box->setDisabled(true);
        password_box->setDisabled(true);
        login_btn->setDisabled(true);
        cancel_btn->setDisabled(true);

        // Show welcome message
        QMessageBox::information(this, "Login", QString("Hello ") + usrname_box->text() + "!");

        // Exit application
        QCoreApplication::exit(0);  // or qApp->quit();
    }

    /**
     * @brief Slot executed when the cancel button is pressed.
     */
    void EnterCancel() {
        printf("Canceled\n");
        QMessageBox::warning(this, "Login", "Login canceled.");
        close(); // optional: close the window
    }

private:
    // Layouts
    QVBoxLayout* mainLayout;
    QHBoxLayout* raw_1_Layout;
    QHBoxLayout* raw_2_Layout;
    QHBoxLayout* raw_3_Layout;

    // Widgets
    QLabel* usrname_label;
    QLabel* password_label;
    QLineEdit* usrname_box;
    QLineEdit* password_box;
    QPushButton* login_btn;
    QPushButton* cancel_btn;
};

/**
 * @brief Main entry point of the application.
 */
int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    Window win;
    win.show();
    return app.exec();
}

