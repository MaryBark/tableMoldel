include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "stateVectorModel.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

     ui->tabWidget->tabBar()->hide();

//     QList <double> mq {10.0 , 10.0 , 10.0 , 10.0 , 10.0 ,10.0};

     QByteArray mq = QString("123456789345345").toUtf8();

    stateVectorModel *statVec = new stateVectorModel(mq, this);
    ui->tableView->setModel(statVec);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->tabWidget->setCurrentIndex(0);
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->tabWidget->setCurrentIndex(1);
    ui->stackedWidget->setCurrentIndex(1);
}
