#ifndef INCOMING_H
#define INCOMING_H

#include <QDialog>
#include "databaseserver.h"
#include "password.h"
#include "registration.h"

namespace Ui {
class incoming;
}

class incoming : public QDialog
{
    Q_OBJECT

public:
    explicit incoming(QWidget *parent = nullptr);
    ~incoming();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::incoming *ui;
};

#endif // INCOMING_H
