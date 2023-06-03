#ifndef DELETEDATA_H
#define DELETEDATA_H

#include <QDialog>
#include <QDebug>
#include "databaseserver.h"
#include <QSqlQueryModel>
#include <QMessageBox>
namespace Ui {
class deleteData;
}

class QSqlQueryModel;
class deleteData : public QDialog
{
    Q_OBJECT
public:
    explicit deleteData(QWidget *parent = nullptr);
    ~deleteData();

private slots:
    void on_pushButton_clicked();

    void on_exit_clicked();

    void on_deleteData_3_clicked();

private:
    Ui::deleteData *ui;
    QSqlQueryModel *mModel;
};

#endif // DELETEDATA_H
