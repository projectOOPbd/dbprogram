#include "password.h"
#include "ui_password.h"
#include "mainwindow.h"
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
    QSqlQuery query;
    query.prepare("SELECT * FROM users WHERE login = :login AND password = :password");
    query.bindValue(":login", login);
    query.bindValue(":password", password);

    if (query.exec() && query.next())
    {
        QMessageBox::about(this,"ура","ви успішно авторизувалися");
        basadata basa;
        basa.setModal(true);
        basa.exec();
        hide();
    }
    else
    {
        QMessageBox::critical(this,":(","ви не змогли зайти");
    }
}

