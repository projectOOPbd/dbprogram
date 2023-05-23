#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QDialog>
#include <QRegularExpression>
#include <QString>
#include <QMessageBox>
namespace Ui {
class registration;
}

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
};


#endif // REGISTRATION_H
