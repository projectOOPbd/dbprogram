#ifndef ADDDATAINDATABASE_H
#define ADDDATAINDATABASE_H

#include <QDialog>
#include <QString>
#include <QSqlQueryModel>
#include <QMessageBox>
namespace Ui {
class addDataInDatabase;
}

class QSqlQueryModel;

class addDataInDatabase : public QDialog
{
    Q_OBJECT

public:
    explicit addDataInDatabase(QWidget *parent = nullptr);
    ~addDataInDatabase();

private slots:
    void on_addData_clicked();

    void on_pushButton_clicked();

private:
    Ui::addDataInDatabase *ui;
    QSqlQueryModel *mModel;
};

#endif // ADDDATAINDATABASE_H
