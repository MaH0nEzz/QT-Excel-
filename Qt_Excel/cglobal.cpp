#include "cglobal.h"

QString CGlobal::g_qsExcelPath = "";
QString CGlobal::g_qsCreateDirPath = "";
QString CGlobal::g_qsDevType = "";
QString CGlobal::g_qsDevIndex = "";
QString CGlobal::g_qsS_Factory = "";
QString CGlobal::g_qsS_DevType = "";
QString CGlobal::g_qsS_DevIndex = "";
QList<CAIdata> CGlobal::g_qlAIDataList;
QList<CDIdata> CGlobal::g_qlDIDataList;

CGlobal::CGlobal()
{
}
CGlobal::~CGlobal()
{
}

CAIdata::CAIdata(QString MeteID,QString MeteName)
{
    N_MeteID = MeteID;
    N_MeteName = MeteName;
}

CDIdata::CDIdata(QString MeteID,QString MeteName)
{
    N_MeteID = MeteID;
    N_MeteName = MeteName;
}
