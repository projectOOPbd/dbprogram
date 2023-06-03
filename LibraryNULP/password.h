#ifndef PASSWORD_H
#define PASSWORD_H

#include <QDialog>
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include "databaseserver.h"
#include "basadata.h"
namespace Ui {
class password;
}

class DatabaseServer;

class password : public QDialog
{
    Q_OBJECT

public:
    explicit password(QWidget *parent = nullptr);
    ~password();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::password *ui;
    DatabaseServer mDbConnection;
};

#endif // PASSWORD_H
