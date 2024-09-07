#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /* 메뉴바 추가 */
    QMenu *menuHelp = new QMenu();
    menuHelp->setTitle("&Help");
    menuHelp->setVisible(true);
    menuHelp->show();

    /* 메뉴바의 액션(하위 메뉴) 추가 */
    QAction *actionAbout = new QAction();
    actionAbout->setText("&About");
    menuHelp->addAction(actionAbout);

    /****************************************
     * stack widget setting                 *
     ***************************************/

    /* 각 페이지를 변수에 저장 */
    QWidget *page_blockCipher = ui->stackedWidget->widget(0);   // block cipher 페이지
    QWidget *page_MAC = ui->stackedWidget->widget(1);           // MAC 페이지

    /* block cipher 버튼 - block cipher 페이지 */
    connect(ui->btn_blockCipher, &QPushButton::clicked, [this, page_blockCipher]() {
        ui->stackedWidget->setCurrentWidget(page_blockCipher);  // 첫 번째 페이지로 전환
    });

    /* block cipher 버튼 - block cipher 페이지 */
    connect(ui->btn_MAC, &QPushButton::clicked, [this, page_MAC]() {
        ui->stackedWidget->setCurrentWidget(page_MAC);  // 첫 번째 페이지로 전환
    });

    /* 위젯과 Slot(function)을 연결*/
    connect(actionAbout, SIGNAL(triggered(bool)), this, SLOT(on_actionAbout_triggered()));

    ui->menubar->addMenu(menuHelp);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionExit_triggered()
{
    // QMessageBox::information(this, "Menu bar test", "File-Exit menu");
    QCoreApplication::quit();
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::information(this, "Menu bar test", "Help-About menu");
}

// void MainWindow::on_btn_blockCipher_clicked()
// {
//     ui->stackedWidget->setCurrentWidget(page_blockCipher);
// }

