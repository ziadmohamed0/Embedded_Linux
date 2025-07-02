#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

float firstNum, secoundNum, reslut;

void MainWindow::on_btn_mult_clicked()
{
    firstNum= ui->inNum1->text().toInt();
    secoundNum= ui->inNum2->text().toInt();

    reslut = (firstNum*secoundNum);
    ui->outResult->setText(QString::number(reslut));
}


void MainWindow::on_btn_divid_clicked()
{
    firstNum = ui->inNum1->text().toInt();
    secoundNum = ui->inNum2->text().toInt();

    reslut = (firstNum/secoundNum);
    ui->outResult->setText(QString::number(reslut));
}


void MainWindow::on_btn_sum_clicked()
{
    firstNum = ui->inNum1->text().toInt();
    secoundNum = ui->inNum2->text().toInt();

    reslut = (firstNum+secoundNum);
    ui->outResult->setText(QString::number(reslut));
}


void MainWindow::on_btn_sub_clicked()
{
    firstNum = ui->inNum1->text().toInt();
    secoundNum = ui->inNum2->text().toInt();

    reslut = (firstNum-secoundNum);
    ui->outResult->setText(QString::number(reslut));
}

