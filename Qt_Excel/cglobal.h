#ifndef CGLOBAL_H
#define CGLOBAL_H

#include <QObject>

class CAIdata
{
public:

    QString N_MeteID;
    QString N_MeteName;

    CAIdata(){}
    CAIdata(QString MeteID,QString MeteName);
    ~CAIdata(){}

};

class CDIdata
{
public:

    QString N_MeteID;
    QString N_MeteName;

    CDIdata(){}
    CDIdata(QString MeteID,QString MeteName);
    ~CDIdata(){}

};

class CGlobal
{
public:
    CGlobal();
    ~CGlobal();

public:
    static QString g_qsExcelPath;
    static QString g_qsCreateDirPath;
    static QString g_qsDevType;
    static QString g_qsDevIndex;
    static QString g_qsS_Factory;
    static QString g_qsS_DevType;
    static QString g_qsS_DevIndex;
    static QList<CAIdata> g_qlAIDataList;
    static QList<CDIdata> g_qlDIDataList;
};



#endif // CGLOBAL_H
