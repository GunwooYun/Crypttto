#ifndef PAGEHASH_H
#define PAGEHASH_H

#include <QWidget>

namespace Ui {
class PageHash;
}

class PageHash : public QWidget
{
    Q_OBJECT

public:
    explicit PageHash(QWidget *parent = nullptr);
    ~PageHash();

private:
    Ui::PageHash *ui;

};

#endif // PAGEHASH_H
