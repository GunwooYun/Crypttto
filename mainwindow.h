#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

enum ePageIndex
{
    PAGE_HOME = 0,
    PAGE_BLOCK_CIPHER_INDEX,    // 1
    PAGE_HASH_INDEX,            // 2
    PAGE_MAC_INDEX              // 3

};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionExit_triggered();
    void on_actionAbout_triggered();

    // void on_btn_blockCipher_clicked();

    void on_btn_blockCipher_clicked();

    void on_btn_MAC_clicked();

    void on_btn_hash_clicked();

private:
    Ui::MainWindow *ui;


private: /* Pages */
    QWidget *page_home;
    QWidget *page_blockCipher;
    QWidget *page_MAC;
    QWidget *page_hash;

};
#endif // MAINWINDOW_H
