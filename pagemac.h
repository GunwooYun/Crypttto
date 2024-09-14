#ifndef PAGEMAC_H
#define PAGEMAC_H

#include <QWidget>

namespace Ui {
class PageMAC;
}

class PageMAC : public QWidget
{
    Q_OBJECT

public:
    explicit PageMAC(QWidget *parent = nullptr);
    ~PageMAC();

private:
    Ui::PageMAC *ui;
};

#endif // PAGEMAC_H
