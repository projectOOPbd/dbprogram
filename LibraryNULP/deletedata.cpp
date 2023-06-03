#include "deletedata.h"
#include "ui_deletedata.h"

deleteData::deleteData(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deleteData)
{
    ui->setupUi(this);
    mModel = nullptr;
}

deleteData::~deleteData()
{
    delete ui;
}

void deleteData::on_exit_clicked()
{
    this->close();
}


void deleteData::on_deleteData_3_clicked()
{
    QString id = ui->deleteData_2->text();
    if(mModel == nullptr)
    {
        mModel = new QSqlQueryModel(this);
        mModel->setQuery("DELETE FROM book  WHERE id ="+id+";");
        hide();
        QMessageBox::about(this,"ви дуже круті","елемент видалено");
    }
    qDebug()<<id;
}

