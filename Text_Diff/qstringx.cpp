#include "qstringx.h"
#include <QVector>

QStringX::QStringX()
{
    InitDiffRes("");
}

void QStringX::InitDiffRes (const QString &strRes)
{
    m_strDiffRes = strRes;
}

QString QStringX::GetDiffRes () const
{
    return m_strDiffRes;
}

QString QStringX::String_Common (const QString& strA,const QString& strB)
{
    QString strTempA = strA;
    QString strTempB = strB;

    if(strTempA.length () < strTempA.length ())
    {
        QString strTemp = strTempA;
        strTempA = strTempB;
        strTempB = strTemp;
    }

    int ilenSubStr = 0;
    int iEnd = 0;
    QVector<int> vFlag(strTempA.length(),0);

    for(int iB = 0;iB < strTempB.length();iB++)
    {
        for(int iA = strTempA.length() - 1;iA >= 0;iA--)
        {
            if(strTempA[iA] == strTempB[iB])
            {
                if((iA == 0)||(iB == 0))
                {
                    vFlag[iA] = 1;
                }
                else
                {
                    vFlag[iA] = vFlag[iA - 1] + 1;
                }
            }
            else
            {
                vFlag[iA] = 0;
            }

            if(vFlag[iA] > ilenSubStr)
            {
                ilenSubStr = vFlag[iA];
                iEnd = iA;
            }
        }

    }

    return strTempA.mid (iEnd - ilenSubStr + 1,ilenSubStr);
}

QString QStringX::String_Fill(const QString& strA,const QString& strB)
{
    QString strRes;
    int lenA = strA.length ();
    int lenB = strB.length ();

    if((lenA == 0)&&(lenB == 0))
    {
        return "";
    }

    if(lenA > lenB)
    {
        strRes = strA.left (lenA - lenB);
        strRes.append ("(-)");
        strRes += strB;

        strRes = lenB == 0 ? strRes : strRes.append ("($)");

    }
    else
        if(lenA == lenB)
        {
            strRes = strB;
            strRes.append ("($)");
        }
        else
        {
            strRes = strB.left(lenB - lenA);
            strRes.append ("(+)");
            strRes.append ((strB.right(lenA)));

            strRes = lenA == 0 ? strRes : strRes.append ("($)");
        }

    return strRes;
}

QString QStringX::String_Diff(const QString& strA,const QString& strB)
{
    QString strCommon = String_Common(strA,strB);

    if(strCommon == "")
    {
        m_strDiffRes += String_Fill(strA,strB);
    }
    else
    {
        QString sA1 = strA.left(strA.indexOf (strCommon));
        QString sB1 = strB.left(strB.indexOf (strCommon));

        String_Diff(sA1,sB1);

        m_strDiffRes += strCommon;
        m_strDiffRes.append ("(=)");

        QString sA2 = strA.right(strA.length() - strCommon.length() - strA.indexOf(strCommon));
        QString sB2 = strB.right(strB.length() - strCommon.length() - strB.indexOf(strCommon));

        String_Diff(sA2,sB2);
    }

    return m_strDiffRes;
}
