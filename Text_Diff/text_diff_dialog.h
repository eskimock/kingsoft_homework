#ifndef TEXT_DIFF_DIALOG_H
#define TEXT_DIFF_DIALOG_H

#include <QDialog>
#include <QDir>

QT_BEGIN_NAMESPACE
class QLabel;
class QLineEdit;
class QPushButton;
class QTableWidget;
class QTableWidgetItem;
QT_END_NAMESPACE

namespace Ui {
    class Text_Diff_Dialog;
}

class Text_Diff_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Text_Diff_Dialog(QWidget *parent = 0);
    ~Text_Diff_Dialog();


private:
    Ui::Text_Diff_Dialog *ui;

private slots:
    void on_diffBtn_clicked();
    void on_browseBtnB_clicked();
    void on_browseBtnA_clicked();

private:
    QString GetFileContent(const QString& strFileDir,QIODevice::OpenMode openMode = QIODevice::ReadOnly | QIODevice::Text);

};

#endif // TEXT_DIFF_DIALOG_H
