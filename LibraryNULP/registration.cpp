#include "registration.h"
#include "ui_registration.h"

registration::registration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registration),mDbConnection("DESKTOP-KTTQUC7",
                                           "SQL SERVER",
                                           "sa",
                                           "fZYuM?=B9<zY5xF",
                                           "libraryNULP",
                                           true)
{
    ui->setupUi(this);
}

registration::~registration()
{
    delete ui;
}

void CheckPasswordStrength(QString password)
{
    int minLength = 10;
    QRegularExpression pattern("(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[!@#$%^&*()])");
    if (password.length() < minLength)
    {
        throw std::runtime_error("Пароль замаленький.");
    }
    QRegularExpressionMatch match = pattern.match(password);
    if (!match.hasMatch())
    {
         throw std::runtime_error("Пароль ненадійний.");
    }
}

void ComparePasswords(QString password,QString passwordConfirm)
{
    if(password != passwordConfirm)
    {
        throw std::runtime_error("паролі не сходяться");
    }
}
void registration::on_next_clicked()
{
    QString name,surname,nameMail,password,passwordConfim;
    QString error = "База не підключена";
    name = ui->name->text();
    surname = ui->surname->text();
    nameMail = ui->nameMail->text()+"@gmail.com";
    password = ui->password->text();
    passwordConfim = ui->passportConfirm->text();
    if(!mDbConnection.openDataBase(&error))
    {
        QMessageBox::critical(this,"error",error);
        return;
    }
    mModel = nullptr;
    try
    {
        CheckPasswordStrength(password);
        ComparePasswords(password,passwordConfim);
        if(mModel == nullptr)
        {
            mModel = new QSqlQueryModel(this);
            mModel->setQuery("INSERT INTO users(name, surname, login, password) VALUES ('"+name+"','"+surname+"','"+nameMail+"','"+password+"');");
        }
        hide();
        QMessageBox::about(this,"Текст","Вас успішно додано приємного користування");
    }catch(const std::exception& e)
    {
        QMessageBox::critical(this,"Помилка",e.what());
    }
}


void registration::on_exit_clicked()
{
    this->close();
}

