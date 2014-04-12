/********************************************************************************
** Form generated from reading UI file 'text_diff_dialog.ui'
**
** Created: Mon Mar 24 19:28:15 2014
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEXT_DIFF_DIALOG_H
#define UI_TEXT_DIFF_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Text_Diff_Dialog
{
public:
    QLabel *fileLableA;
    QLineEdit *fileDirEditA;
    QPushButton *browseBtnA;
    QLabel *fileLabelB;
    QPushButton *browseBtnB;
    QLineEdit *fileDirEditB;
    QPushButton *diffBtn;

    void setupUi(QDialog *Text_Diff_Dialog)
    {
        if (Text_Diff_Dialog->objectName().isEmpty())
            Text_Diff_Dialog->setObjectName(QString::fromUtf8("Text_Diff_Dialog"));
        Text_Diff_Dialog->resize(672, 420);
        fileLableA = new QLabel(Text_Diff_Dialog);
        fileLableA->setObjectName(QString::fromUtf8("fileLableA"));
        fileLableA->setGeometry(QRect(30, 50, 121, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Agency FB"));
        font.setPointSize(14);
        fileLableA->setFont(font);
        fileDirEditA = new QLineEdit(Text_Diff_Dialog);
        fileDirEditA->setObjectName(QString::fromUtf8("fileDirEditA"));
        fileDirEditA->setGeometry(QRect(80, 100, 341, 31));
        browseBtnA = new QPushButton(Text_Diff_Dialog);
        browseBtnA->setObjectName(QString::fromUtf8("browseBtnA"));
        browseBtnA->setGeometry(QRect(490, 100, 121, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Agency FB"));
        font1.setPointSize(12);
        browseBtnA->setFont(font1);
        fileLabelB = new QLabel(Text_Diff_Dialog);
        fileLabelB->setObjectName(QString::fromUtf8("fileLabelB"));
        fileLabelB->setGeometry(QRect(30, 160, 121, 31));
        fileLabelB->setFont(font);
        browseBtnB = new QPushButton(Text_Diff_Dialog);
        browseBtnB->setObjectName(QString::fromUtf8("browseBtnB"));
        browseBtnB->setGeometry(QRect(490, 210, 121, 31));
        browseBtnB->setFont(font1);
        fileDirEditB = new QLineEdit(Text_Diff_Dialog);
        fileDirEditB->setObjectName(QString::fromUtf8("fileDirEditB"));
        fileDirEditB->setGeometry(QRect(80, 210, 341, 31));
        diffBtn = new QPushButton(Text_Diff_Dialog);
        diffBtn->setObjectName(QString::fromUtf8("diffBtn"));
        diffBtn->setGeometry(QRect(260, 290, 161, 71));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Agency FB"));
        font2.setPointSize(14);
        font2.setBold(false);
        font2.setWeight(50);
        diffBtn->setFont(font2);

        retranslateUi(Text_Diff_Dialog);

        QMetaObject::connectSlotsByName(Text_Diff_Dialog);
    } // setupUi

    void retranslateUi(QDialog *Text_Diff_Dialog)
    {
        Text_Diff_Dialog->setWindowTitle(QApplication::translate("Text_Diff_Dialog", "\346\226\207\346\234\254\345\267\256\345\274\202\345\210\206\346\236\220", 0, QApplication::UnicodeUTF8));
        fileLableA->setText(QApplication::translate("Text_Diff_Dialog", "\350\257\267\351\200\211\346\213\251\346\226\207\346\234\254A\357\274\232", 0, QApplication::UnicodeUTF8));
        browseBtnA->setText(QApplication::translate("Text_Diff_Dialog", "\346\265\217  \350\247\210", 0, QApplication::UnicodeUTF8));
        fileLabelB->setText(QApplication::translate("Text_Diff_Dialog", "\350\257\267\351\200\211\346\213\251\346\226\207\346\234\254B\357\274\232", 0, QApplication::UnicodeUTF8));
        browseBtnB->setText(QApplication::translate("Text_Diff_Dialog", "\346\265\217  \350\247\210", 0, QApplication::UnicodeUTF8));
        diffBtn->setText(QApplication::translate("Text_Diff_Dialog", "\350\277\233\350\241\214\345\267\256\345\274\202\345\210\206\346\236\220", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Text_Diff_Dialog: public Ui_Text_Diff_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEXT_DIFF_DIALOG_H
