#include "registration.h"
#include "ui_registration.h"

registration::registration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registration)
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
/*void checkInput(const QLineEdit* lineEdit)
{
    if (lineEdit->text().isEmpty())
    {
        ui->lineEdit->setText("Заповніть поле");
    }
    lineEdit
}*/
void registration::on_next_clicked()
{
    QString name,surname,nameMail,password,passwordConfim;
    name = ui->name->text();
    surname = ui->surname->text();
    nameMail = ui->nameMail->text();
    password = ui->password->text();
    passwordConfim = ui->passportConfirm->text();
    try
    {
        CheckPasswordStrength(password);
        ComparePasswords(password,passwordConfim);
    }catch(const std::exception& e)
    {
        QMessageBox::critical(this,"Помилка",e.what());
    }
    hide();
    QMessageBox::about(this,"Текс","Вас успішно додано приємного користування");
}


void registration::on_exit_clicked()
{
    this->close();
}

