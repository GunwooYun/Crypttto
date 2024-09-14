#include "pagehome.h"
#include "ui_pagehome.h"

PageHome::PageHome(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PageHome)
{
    ui->setupUi(this);
}

PageHome::~PageHome()
{
    delete ui;
}
