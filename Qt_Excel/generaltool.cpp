#include "generaltool.h"

int Fun_MessageBox(const char* str1,const char* str2)
{
    QMessageBox msgBox(str1,		///--这里是设置消息框标题
            str2,						///--这里是设置消息框显示的内容
            QMessageBox::Warning,							///--这里是在消息框显示的图标
            QMessageBox::Ok | QMessageBox::Default,		///---这里是显示消息框上的按钮情况
            QMessageBox::Cancel | QMessageBox::Escape,	///---这里与 键盘上的 escape 键结合。当用户按下该键，消息框将执行cancel按钮事件
            0);

   msgBox.show();

   return msgBox.exec();


}
