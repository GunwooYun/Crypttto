#include "pagehash.h"
#include "ui_PageHash.h"

PageHash::PageHash(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageHash)
{
    ui->setupUi(this);

    ui->cb_Algorithm->addItem("SHA1");
    ui->cb_Algorithm->addItem("SHA224");
    ui->cb_Algorithm->addItem("SHA256");
    ui->cb_Algorithm->addItem("SHA384");
    ui->cb_Algorithm->addItem("SHA512");
}

PageHash::~PageHash()
{
    delete ui;
}
