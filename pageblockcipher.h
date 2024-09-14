#ifndef PAGEBLOCKCIPHER_H
#define PAGEBLOCKCIPHER_H

#include <QWidget>

namespace Ui {
class PageBlockCipher;
}

class PageBlockCipher : public QWidget
{
    Q_OBJECT

public:
    explicit PageBlockCipher(QWidget *parent = nullptr);
    ~PageBlockCipher();

private:
    Ui::PageBlockCipher *ui;
};

#endif // PAGEBLOCKCIPHER_H
