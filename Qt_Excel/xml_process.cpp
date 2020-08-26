#include "xml_process.h"
#include "generaltool.h"
#include "cglobal.h"
#include <QDebug>

using namespace tinyxml2;

int createXML(const char* xmlPath)
{
    XMLDocument doc;
    if(3 != doc.LoadFile(xmlPath))
    {
        qDebug() <<"file has been existed !";
        return 0;
     }

    //添加申明可以使用如下两行
    XMLDeclaration* declaration=doc.NewDeclaration(VERSION_ENCODING_STANDALONE);
    doc.InsertFirstChild(declaration);

    XMLElement* root=doc.NewElement("XMLUSER");
    doc.InsertEndChild(root);


    XMLElement* userNode = doc.NewElement("User");
    /*添加属性*/
    userNode->SetAttribute("Name","张政");
    userNode->SetAttribute("Password ","bbbbbb");
    root->InsertEndChild(userNode);

    return doc.SaveFile(xmlPath);
}

int CreateNorth_vs_Southxml(const char* xmlPath)
{
    //首先判断下变量填好了没
    if(CGlobal::g_qsDevIndex == "")
    {
        return  Fun_MessageBox("警告","尚未添加设备索引(DevIndex)");
    }

    if(CGlobal::g_qsS_Factory == "")
    {
        return  Fun_MessageBox("警告","尚未添加南向厂家ID(S_Factory)");
    }

    if(CGlobal::g_qsS_DevType == "")
    {
        return  Fun_MessageBox("警告","尚未添加南向设备类型(S_DevType)");
    }

    if(CGlobal::g_qsS_DevIndex == "")
    {
        return  Fun_MessageBox("警告","尚未添加南向设备索引(S_DevIndex)");
    }

    //然后创建xml文件咯
    XMLDocument doc;
    if(3 != doc.LoadFile(xmlPath))
    {
        qDebug() <<"file has been existed !";
        return  Fun_MessageBox("警告","xml文件已存在!");
    }

    //添加申明可以使用如下两行
    XMLDeclaration* declaration=doc.NewDeclaration(VERSION_ENCODING_STANDALONE);
    doc.InsertFirstChild(declaration);

    XMLElement* root=doc.NewElement("Doc");

    doc.InsertEndChild(root);

    root=doc.RootElement();

    XMLElement* North_Node = doc.NewElement("North");
    North_Node->SetAttribute("DevType","52");
    North_Node->SetAttribute("DevIndex","0");
    root->InsertEndChild(North_Node);

    int i = 0;
    for(i = 0; i <CGlobal::g_qlAIDataList.size();i++)
    {
        XMLElement* N_vs_S_Node = doc.NewElement("N_VS_S");
        N_vs_S_Node->SetAttribute("N_MeteName",CGlobal::g_qlAIDataList.at(i).N_MeteName.toStdString().c_str());
        N_vs_S_Node->SetAttribute("N_MeteID",CGlobal::g_qlAIDataList.at(i).N_MeteID.toStdString().c_str());
        N_vs_S_Node->SetAttribute("N_MeteIndex","0");
        N_vs_S_Node->SetAttribute("S_Factory",CGlobal::g_qsS_Factory.toStdString().c_str());
        N_vs_S_Node->SetAttribute("S_DevType",CGlobal::g_qsS_DevType.toStdString().c_str());
        N_vs_S_Node->SetAttribute("S_DevIndex",CGlobal::g_qsS_DevIndex.toStdString().c_str());
        N_vs_S_Node->SetAttribute("S_Chnnl",QString::number(i).toStdString().c_str());
        N_vs_S_Node->SetAttribute("S_ChnnlType","AI");
        North_Node->InsertEndChild(N_vs_S_Node);
    }

    doc.SaveFile(xmlPath);

    return Fun_MessageBox("提示","已生成!");
}

