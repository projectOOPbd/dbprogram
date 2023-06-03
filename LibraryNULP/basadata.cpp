#include "basadata.h"
#include "ui_basadata.h"

basadata::basadata(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::basadata)
{
    ui->setupUi(this);
    mModel = nullptr;
    if(mModel == nullptr)
    {
        mModel = new QSqlQueryModel(this);
        mModel->setQuery("SELECT id,nameBook,author,gpa FROM book;");
        ui->tableView->setModel(mModel);
       }
}

basadata::~basadata()
{
    delete ui;
}

void basadata::on_exit_clicked()
{
    this->close();
}


void basadata::on_addNewData_clicked()
{
    addDataInDatabase data;
    data.setModal(true);
    data.exec();
}


void basadata::on_pushButton_clicked()
{
    mModel->setQuery("SELECT id,nameBook,author,gpa FROM book;");
    ui->tableView->setModel(mModel);
}


void basadata::on_delete_2_clicked()
{
    deleteData data;
    data.setModal(true);
    data.exec();
}

