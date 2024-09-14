#include "pagemac.h"
#include "ui_pagemac.h"

PageMAC::PageMAC(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PageMAC)
{
    ui->setupUi(this);
}

PageMAC::~PageMAC()
{
    delete ui;
}
