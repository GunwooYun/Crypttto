#include "pagehash.h"
#include "ui_PageHash.h"

PageHash::PageHash(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageHash)
{
    ui->setupUi(this);
}

PageHash::~PageHash()
{
    delete ui;
}
