#ifndef DATABASE_H
#define DATABASE_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include <QSqlQueryModel>
#include "adddataindatabase.h"

namespace Ui {
class database;
}

class QSqlQueryModel;

class database : public QDialog
{
    Q_OBJECT

public:
    explicit database(QWidget *parent = nullptr);
    ~database();

private slots:
    void on_deleteData_2_clicked();

    void on_addData_clicked();

private:
    Ui::database *ui;   
    QSqlQueryModel *mModel;
};

#endif // DATABASE_H
