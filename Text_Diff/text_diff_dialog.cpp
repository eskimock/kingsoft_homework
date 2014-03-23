#include "text_diff_dialog.h"
#include "ui_text_diff_dialog.h"

#include <qfile.h>
#include <qtextstream.h>

#include <QtGui>

Text_Diff_Dialog::Text_Diff_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Text_Diff_Dialog)
{
    ui->setupUi(this);

    ui->fileDirEditA->setReadOnly (true);
    ui->fileDirEditB->setReadOnly (true);

}

Text_Diff_Dialog::~Text_Diff_Dialog()
{
    delete ui;
}



void Text_Diff_Dialog::on_browseBtnA_clicked()
{
    QString strDirA = QFileDialog::getOpenFileName(this,tr("Text_Diff"), QDir::currentPath(), tr("TEXT files (*.txt);;All files(*.*)"));

    if (!strDirA.isEmpty())
    {
        ui->fileDirEditA->setText (strDirA);
    }
}

void Text_Diff_Dialog::on_browseBtnB_clicked()
{
    QString strDirB = QFileDialog::getOpenFileName(this,tr("Text_Diff"), QDir::currentPath(), tr("TEXT files (*.txt);;All files(*.*)"));

    if (!strDirB.isEmpty())
    {
        ui->fileDirEditB->setText (strDirB);
    }
}

void Text_Diff_Dialog::on_diffBtn_clicked()
{
    QString strFileDirA = ui->fileDirEditA->text ();
    QString strFileDirB = ui->fileDirEditB->text ();

    if((strFileDirA == tr("")) || (strFileDirB == tr("")))
    {
        QMessageBox::information(NULL, tr("Warning"), tr("No File Chosen!!"));
    }
    else
    {
        QString strContentA = GetFileContent(strFileDirA);
        QString strContentB = GetFileContent(strFileDirB);
    }

}

QString Text_Diff_Dialog::GetFileContent(const QString& strFileDir,QIODevice::OpenMode openMode /*= QIODevice::ReadOnly | QIODevice::Text*/)
{
    QFile file(strFileDir);
    if(!file.open(openMode))
    {
        QMessageBox::information(NULL, tr("Warning"), tr("Failed to Open File!!"));
        return tr("");
    }
    else
    {
        QTextStream ReadFile(&file);
        QString strContent = ReadFile.readAll ();
        file.close();

        return strContent;
    }
}
