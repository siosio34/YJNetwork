#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    PacketUtil DevPacket;
    DevPacket.show();
    DevPacket.exec();


    if(DevPacket.GetHandle() != NULL)
       ui->setupUi(this);

    else{
    }
       // QMessageBox::information(NULL,"Error","This Devise's' HANDLE Can't Find");


}

MainWindow::~MainWindow()
{
    delete ui;
}
