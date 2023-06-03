#include "incoming.h"
#include "ui_incoming.h"

incoming::incoming(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::incoming)
{
    ui->setupUi(this);
}

incoming::~incoming()
{
    delete ui;
}

void incoming::on_pushButton_clicked()
{
        registration reg;
    reg.setModal(true);
    reg.exec();
}


void incoming::on_pushButton_2_clicked()
{
    password pass;
    pass.setModal(true);
    pass.exec();
}



void incoming::on_pushButton_3_clicked()
{
    this->close();
}

