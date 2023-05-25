#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QDialog>
#include <QRegularExpression>
#include <QString>
#include <QMessageBox>
#include "databaseserver.h"
#include <QSqlQueryModel>

namespace Ui {
class registration;
}

class DatabaseServer;
class QSqlQueryModel;
class registration : public QDialog
{
    Q_OBJECT

public:
    explicit registration(QWidget *parent = nullptr);
    ~registration();

private slots:
    void on_pushButton_clicked();

    void on_next_clicked();

    void on_exit_clicked();

private:
    Ui::registration *ui;
    DatabaseServer mDbConnection;
    QSqlQueryModel *mModel;
};


#endif // REGISTRATION_H
