#ifndef BASADATA_H
#define BASADATA_H

#include <QDialog>
#include <QDialog>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include <QSqlQueryModel>
#include "adddataindatabase.h"
#include "deletedata.h"
namespace Ui {
class basadata;
}

class basadata : public QDialog
{
    Q_OBJECT

public:
    explicit basadata(QWidget *parent = nullptr);
    ~basadata();

private slots:
    void on_exit_clicked();

    void on_addNewData_clicked();

    void on_pushButton_clicked();

    void on_delete_2_clicked();

private:
    Ui::basadata *ui;
    QSqlQueryModel *mModel;
};

#endif // BASADATA_H
