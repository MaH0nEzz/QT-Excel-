#include "getexceldata.h"
#include "generaltool.h"
#include <QObject>


int GetDataFromExcel()
{
    //CGlobal::g_qlAIDataList

    if(CGlobal::g_qsExcelPath == "")
    {
        return  Fun_MessageBox("警告","尚未选择Excel文件路径");
    }

    if(CGlobal::g_qsDevType == "")
    {
       return  Fun_MessageBox("警告","尚未输入设备类型");
    }

    //先把两个链表给清了，要不然再点获取的话就会再加到链表里
    //也考虑过添加个锁啥的,暂时先不搞，关键是不知道这个获取
    //时间为啥这么长，可能是调用VB语言的关系，而且这个excel
    //也是在后台中运行
    CGlobal::g_qlAIDataList.clear();
    CGlobal::g_qlDIDataList.clear();


    ExcelOperator Excel;

    //首先打开Excel文件
    Excel.open(CGlobal::g_qsExcelPath);

    //根据名称表名称获取工作表(例如遥调,遥测等)这里首先获得遥测工作表
    QAxObject* AISheet = Excel.getSheet("遥测");

    int AIflag = 0;
    for(int i = 1;i < 1000;i++)//从1开始是因为EXCEL没有第0行
    {
        if(CGlobal::g_qsDevType != Excel.getCell(AISheet,i,2))
        {
            if(AIflag == 0)
            {
                continue;
            }

            if(AIflag == 1)
            {
                break;
            }
        }

        CAIdata tempAI(Excel.getCell(AISheet,i,1),Excel.getCell(AISheet,i,3));
        //qDebug()<<tempAI.N_MeteID <<tempAI.N_MeteName;
        CGlobal::g_qlAIDataList.push_back(tempAI);
        AIflag = 1;
    }

    QAxObject* DISheet = Excel.getSheet("遥信");

    int DIflag = 0;
    for(int i = 1;i < 1000;i++)
    {
        if(CGlobal::g_qsDevType != Excel.getCell(DISheet,i,2))
        {
            if(DIflag == 0)
            {
                continue;
            }

            if(DIflag == 1)
            {
                break;
            }
        }

        CDIdata tempDI(Excel.getCell(DISheet,i,1),Excel.getCell(DISheet,i,3));
        //qDebug()<<tempDI.N_MeteID <<tempDI.N_MeteName;
        CGlobal::g_qlDIDataList.push_back(tempDI);
        DIflag = 1;
    }

    //QString B68 = Excel.getCell(AISheet,68,2);//这个函数68代表的是行，2代表列，坑惨了
    //qDebug() << "B68:" << B68;


    Excel.close();

    //这个messagebox比较特殊，要显示变量，所以也不知道要显示多少条变量，只能用一次写一次
    QMessageBox mess(QMessageBox::Warning, "提示",
                     QObject::tr("获取到AI量%1条\n 获取到DI量%2条").arg(CGlobal::g_qlAIDataList.size()).arg(CGlobal::g_qlDIDataList.size()), nullptr);
    mess.show();





    return mess.exec();
}
