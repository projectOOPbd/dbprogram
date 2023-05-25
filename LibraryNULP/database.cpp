#include "database.h"
#include "ui_database.h"

database::database(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::database)
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

database::~database()
{
    delete ui;
}

void database::on_deleteData_2_clicked()
{
    this->close();
}


void database::on_addData_clicked()
{
    hide();
    addDataInDatabase data;
    data.setModal(true);
    data.exec();
}

