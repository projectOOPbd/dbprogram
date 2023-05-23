#include "password.h"
#include "ui_password.h"
#include "mainwindow.h"
#include "database.h"

password::password(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::password)
{
    ui->setupUi(this);
}

password::~password()
{
    delete ui;
}

void password::on_pushButton_2_clicked()
{
    this->close();
}


void password::on_pushButton_clicked()
{
    QString login,password;
    login = ui->login->text();
    password = ui->password_2->text();
    if(login == "oleksandr.babiuk@gmail.com" && password == "standardsseem")
    {
        QMessageBox::information(this,"Ура","Ви успішно авторизувалися");
        hide();
        database data;
        data.setModal(true);
        data.exec();
    }
    else
    {
        QMessageBox::warning(this,":(","Ви не змоглив авторизуватися провірьте логін або пароль");
    }
}

