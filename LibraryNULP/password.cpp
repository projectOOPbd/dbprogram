#include "password.h"
#include "ui_password.h"
#include "mainwindow.h"
#include "database.h"
#include "databaseserver.h"

password::password(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::password),mDbConnection("DESKTOP-KTTQUC7",
                                       "SQL SERVER",
                                       "sa",
                                       "fZYuM?=B9<zY5xF",
                                       "libraryNULP",
                                       true)
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
    QString error = "База не підключена";
    login = ui->login->text();
    password = ui->password_2->text();
    if(!mDbConnection.openDataBase(&error))
    {
        QMessageBox::critical(this,"error",error);
        return;
    }
    if(login == "1" && password == "0")
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

