#ifndef QSTRINGX_H
#define QSTRINGX_H

#include <QString>

class QStringX : public QString
{

public:
    QStringX();

public:
    static QString String_Common(const QString& strA,const QString& strB);
    static QString String_Fill(const QString& strA,const QString& strB);
    static QString String_Diff(const QString& strA,const QString& strB);
};

#endif // QSTRINGX_H
