#include "mainwindow.h"
#include <QApplication>
#include "exceloperator.h"
#include <QDebug>
#include <QVariant>
#include <QDir>
#include <QCoreApplication>
#include <QFile>

#include <QStyleFactory>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QFile qssfile(":/Ubuntu.qss");
    qssfile.open(QFile::ReadOnly);
    QString qss;
    qss = qssfile.readAll();
    //qDebug()<< qss;
    qssfile.close();
    //QApplication::setStyle(QStyleFactory::create("fusion"));


    MainWindow w;
    w.setStyleSheet(qss);

    w.show();




    return a.exec();




}


