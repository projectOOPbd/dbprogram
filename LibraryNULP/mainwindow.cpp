#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "password.h"
#include "registration.h"
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


void MainWindow::on_pushButton_2_clicked()
{
    password pass;
    pass.setModal(true);
    pass.exec();
}


void MainWindow::on_pushButton_clicked()
{
    registration reg;
    reg.setModal(true);
    reg.exec();
}


void MainWindow::on_pushButton_3_clicked()
{
    this->close();
}

