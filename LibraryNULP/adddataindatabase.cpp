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
    QString id, nameBook, autor, gpa, fishnet,wayToPDF;
    id = ui->idBook->text();
    nameBook = ui->nameBook->text();
    autor = ui->authorofBook->text();
    gpa = ui->gpa->text();
    wayToPDF = ui->wayToPDF_2->text();
    fishnet = ui->wayToPDF->text();
    fishnet.replace('/', '\\');
    if (mModel == nullptr)
    {
        mModel = new QSqlQueryModel(this);

        QFile file(wayToPDF);
        if (file.open(QIODevice::ReadOnly))
        {

            QByteArray pdfData = file.readAll();

            QSqlQuery query;
            query.prepare("INSERT INTO book (id, nameBook, author, gpa, fishnet, pdfFile) VALUES (:id, :nameBook, :author, :gpa, :fishnet, :pdfFile);");

            query.bindValue(":id", id);
            query.bindValue(":nameBook", nameBook);
            query.bindValue(":author", autor);
            query.bindValue(":gpa", gpa);
            query.bindValue(":fishnet", fishnet);
            query.bindValue(":pdfFile", pdfData);
            if (query.exec())
            {
                hide();
                QMessageBox::about(this, "Ви дуже круті", "Елемент додано");
            }
            else
            {
                QMessageBox::critical(this, "Помилка", "Помилка при виконанні запиту до бази даних");
            }

            file.close();
        }
        else
        {
            QMessageBox::critical(this, "Помилка", "Не вдалося відкрити PDF-файл");
        }
    }


}


void addDataInDatabase::on_pushButton_clicked()
{
    this->close();
}


void addDataInDatabase::on_addData_2_clicked()
{
    QString wayToBook;
    wayToBook = QFileDialog::getOpenFileName();
    ui->wayToPDF_2->setText(wayToBook);
}

