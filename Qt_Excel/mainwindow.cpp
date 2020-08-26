#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include "cglobal.h"
#include <QDebug>
#include "xml_process.h"
#include "getexceldata.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->createxmlpushButton->setStyleSheet("background:blue");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ExcelPathPushButton_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(nullptr,"标题",".","*.xlsx");
    CGlobal::g_qsExcelPath = file_name;
    ui->PathdisplaylineEdit->setText(CGlobal::g_qsExcelPath);
    qDebug() << CGlobal::g_qsExcelPath;
}

void MainWindow::on_createxmlpushButton_clicked()
{
    QString file_name = QFileDialog::getExistingDirectory(nullptr,"caption",".");
    CGlobal::g_qsCreateDirPath = file_name;
    ui->CreatePathdisplaylineEdit->setText(CGlobal::g_qsCreateDirPath);
    qDebug() << CGlobal::g_qsCreateDirPath;

}



void MainWindow::on_GetExcelData_clicked()
{
    CGlobal::g_qsDevType = ui->DevTypeLineEdit->text();
    qDebug() << CGlobal::g_qsDevType;



    GetDataFromExcel();

    for(int i = 0;i<CGlobal::g_qlAIDataList.size();i++)
    {
        qDebug() <<" AIMETE_ID:" << CGlobal::g_qlAIDataList.at(i).N_MeteID << " AIMETE_NAME:" << CGlobal::g_qlAIDataList.at(i).N_MeteName;
    }

    for(int i = 0;i<CGlobal::g_qlDIDataList.size();i++)
    {
        qDebug() <<" DIMETE_ID:" << CGlobal::g_qlDIDataList.at(i).N_MeteID << " DIMETE_NAME:" << CGlobal::g_qlDIDataList.at(i).N_MeteName;
    }


}

void MainWindow::on_n_v_s_createpushButton_clicked()
{
    CGlobal::g_qsDevIndex = ui->DevIndexlineEdit->text();
    CGlobal::g_qsS_Factory = ui->S_FactorylineEdit->text();
    CGlobal::g_qsS_DevType = ui->S_DevTypelineEdit->text();
    CGlobal::g_qsS_DevIndex = ui->S_DevIndexlineEdit->text();


    std::string str = CGlobal::g_qsCreateDirPath.toStdString();

    str = str + "/test.xml";

    //createXML(str.c_str());
    CreateNorth_vs_Southxml(str.c_str());
}
