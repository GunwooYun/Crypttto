#include "pageblockcipher.h"
#include "ui_pageblockcipher.h"

PageBlockCipher::PageBlockCipher(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PageBlockCipher)
{
    ui->setupUi(this);
}

PageBlockCipher::~PageBlockCipher()
{
    delete ui;
}
