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
    actionAbout->setText("About");
    menuHelp->addAction(actionAbout);

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
