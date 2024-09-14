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

    /* Widget 인스턴스 생성 */
    pageHome = new PageHome(this);
    pageBlockCipher = new PageBlockCipher(this);
    pageHash = new PageHash(this);
    pageMAC = new PageMAC(this);

    /* Stacked Widget에 page 인스턴스 추가 */
    ui->stackedWidget->addWidget(pageHome);
    ui->stackedWidget->addWidget(pageBlockCipher);
    ui->stackedWidget->addWidget(pageHash);
    ui->stackedWidget->addWidget(pageMAC);

    /* 버튼 - 페이지 출력 함수 연결*/
    connect(ui->btn_blockCipher, SIGNAL(clicked(bool)), this, SLOT(on_btn_blockCipher_clicked));
    connect(ui->btn_hash, SIGNAL(clicked(bool)), this, SLOT(on_btn_hash_clicked()));
    connect(ui->btn_MAC, SIGNAL(clicked(bool)), this, SLOT(on_btn_MAC_clicked()));

    /* 홈페이지 설정 */
    ui->stackedWidget->setCurrentWidget(pageHome);

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
    ui->stackedWidget->setCurrentWidget(pageBlockCipher);

}

void MainWindow::on_btn_MAC_clicked()
{
    ui->stackedWidget->setCurrentWidget(pageMAC);
}

void MainWindow::on_btn_hash_clicked()
{
    ui->stackedWidget->setCurrentWidget(pageHash);
}
