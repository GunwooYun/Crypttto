#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /****************************************
     * menu bar setting                     *
     ***************************************/

    /* 메뉴바에 help 추가 */
    QMenu *menuHelp = new QMenu();
    menuHelp->setTitle("&Help");
    menuHelp->setVisible(true);
    menuHelp->show();

    /* About(help 하위 메뉴) 추가 */
    QAction *actionAbout = new QAction();
    actionAbout->setText("&About");
    menuHelp->addAction(actionAbout);


    /* 액션 About과 동작 함수 연결 */
    connect(actionAbout, SIGNAL(triggered(bool)), this, SLOT(on_actionAbout_triggered()));

    ui->menubar->addMenu(menuHelp);

    /****************************************
     * stack widget setting                 *
     ***************************************/

    /* 각 페이지를 변수에 저장 */
    page_home = ui->stackedWidget->widget(PAGE_HOME);                       /* home 페이지 */
    page_blockCipher = ui->stackedWidget->widget(PAGE_BLOCK_CIPHER_INDEX);  /* block cipher 페이지 */
    page_hash = ui->stackedWidget->widget(PAGE_HASH_INDEX);                 /* Hash 페이지 */
    page_MAC = ui->stackedWidget->widget(PAGE_MAC_INDEX);                   /* MAC 페이지 */


    /* 버튼 - 페이지 출력 함수 연결*/
    connect(ui->btn_blockCipher, SIGNAL(clicked(bool)), this, SLOT(on_btn_blockCipher_clicked));
    connect(ui->btn_hash, SIGNAL(clicked(bool)), this, SLOT(on_btn_hash_clicked()));
    connect(ui->btn_MAC, SIGNAL(clicked(bool)), this, SLOT(on_btn_MAC_clicked()));

    /* 홈페이지 설정 */
    ui->stackedWidget->setCurrentWidget(page_home);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionExit_triggered()
{
    QCoreApplication::quit();
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::information(this, "Menu bar test", "Help-About menu");
}

void MainWindow::on_btn_blockCipher_clicked()
{
    ui->stackedWidget->setCurrentWidget(page_blockCipher);
}

void MainWindow::on_btn_MAC_clicked()
{
    ui->stackedWidget->setCurrentWidget(page_MAC);
}

void MainWindow::on_btn_hash_clicked()
{
    ui->stackedWidget->setCurrentWidget(page_hash);
}
