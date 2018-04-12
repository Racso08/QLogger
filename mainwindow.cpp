#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "logger.h"
#include <QString>

//Testeo
QString array[5] = {"int a = 0;", "int b = 9;","int j = 2;","int y = 8;","int u = 6734;"};
int i ;
logger *l1 = new logger();

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(i >= 4){
        ui->textEdit->setText("The parser ends...\n");
    }else{
    ui->textEdit->append(l1->logMessage(0,"Calling server... \n"));
    ui->textEdit->append(l1->logMessage(3,array[i]).append("\n"));
    i++;
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    QString port = "123";
    ui->textEdit->append(l1->logMessage(0,"Establishing connection with the server... \n"));
    if(ui->lineEdit->text() == port){
        ui->textEdit->append(l1->logMessage(0,"Port checked... \n"));
        ui->pushButton_2->hide();
        ui->lineEdit->setEnabled(false);
    }else{
        ui->textEdit->append(l1->logMessage(2,"Error port is invalid... \n"));
        ui->pushButton_2->hide();
    }
}
