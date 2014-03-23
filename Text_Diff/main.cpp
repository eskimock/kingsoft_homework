#include <QtGui/QApplication>
#include <QTextCodec>
#include "text_diff_dialog.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //支持中文显示
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GB2312"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GB2312"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GB2312"));

    Text_Diff_Dialog txDiffDlg;
    txDiffDlg.show();

    return app.exec();

}
