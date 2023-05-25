#include "adddataindatabase.h"
#include "ui_adddataindatabase.h"

addDataInDatabase::addDataInDatabase(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addDataInDatabase)
{
    ui->setupUi(this);
    mModel = nullptr;
}

addDataInDatabase::~addDataInDatabase()
{
    delete ui;
}

void addDataInDatabase::on_addData_clicked()
{
    QString id,nameBook,autor,gpa,way;
    id = ui->idBook->text();
    nameBook = ui->nameBook->text();
    autor = ui->authorofBook->text();
    gpa = ui->gpa->text();
    way = ui->wayToPDF->text();
    if(mModel == nullptr)
    {
        mModel = new QSqlQueryModel(this);
        mModel->setQuery("INSERT INTO book (id, namebook, author, gpa, pdfFile)"
                         "VALUES ("+id+",'"+nameBook+"','"+autor+"',"+gpa+", (SELECT * FROM OPENROWSET(BULK '"+way+"', SINGLE_BLOB) AS FileData));");
        hide();
        QMessageBox::about(this,"ви дуже круті","елемент додано");
    }
}


void addDataInDatabase::on_pushButton_clicked()
{
    this->close();
}

