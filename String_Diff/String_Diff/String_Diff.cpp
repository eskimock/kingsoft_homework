// String_Diff.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

//查找最大公共子串

CString String_Common(const CString& strA,const CString& strB)
{
	CString strTempA = strA;
	CString strTempB = strB;

	if(strTempA.GetLength() < strTempA.GetLength())
	{
		CString strTemp = strTempA;
		strTempA = strTempB;
		strTempB = strTemp;
	}

	int ilenSubStr = 0;
	int iEnd = 0;
	std::vector<int> vFlag(strTempA.GetLength(),0);

	for(int iB = 0;iB < strTempB.GetLength();iB++)
	{
		for(int iA = strTempA.GetLength() - 1;iA >= 0;iA--)
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

	return strTempA.Mid(iEnd - ilenSubStr + 1,ilenSubStr);
}

//务必确保A和B的最大公共子串为空
CString String_Fill(const CString& strA,const CString& strB)
{
	CString strRes;
	int lenA = strA.GetLength();
	int lenB = strB.GetLength();

	if((lenA == 0)&&(lenB == 0))
	{
		return _T("");
	}

	if(lenA > lenB)
	{
		strRes = strA.Left(lenA - lenB);
		strRes.Append(_T("(-)"));
		strRes += strB;

		strRes = lenB == 0?strRes:strRes+_T("($)");

	}
	else
		if(lenA == lenB)
		{
			strRes = strB;
			strRes += _T("($)");
		}
		else
		{
			strRes = strB.Left(lenB - lenA);
			strRes += _T("(+)");
			strRes.Append(strB.Right(lenA));

			strRes = lenA == 0?strRes:strRes+_T("($)");
		}

		return strRes;
}

//按一定格式将两字符串差异显示出来
//格式：差异分为增加("+"),减少("-"),更改("$"),相同("=")等4种
//      每个标记字符前的字符段为B相对A的差异字符段

CString String_Diff(const CString& strA,const CString& strB)
{
	static CString strRes;
	CString strCommon = String_Common(strA,strB);

	if(strCommon == _T(""))
	{
		strRes += String_Fill(strA,strB);
	}
	else
	{
		CString sA1 = strA.Left(strA.Find(strCommon));
		CString sB1 = strB.Left(strB.Find(strCommon));
		String_Diff(sA1,sB1);

		strRes += strCommon;
		strRes += _T("(=)");

		CString sA2 = strA.Right(strA.GetLength() - strCommon.GetLength() - strA.Find(strCommon));
		CString sB2 = strB.Right(strB.GetLength() - strCommon.GetLength() - strB.Find(strCommon));
		String_Diff(sA2,sB2);

	}

	return strRes;
}

int _tmain(int argc, _TCHAR* argv[])
{
	CString A(_T("hello korld!!"));
	CString B(_T("heIIo world!!"));

	wprintf_s(_T("%s\n"),String_Fill(A,B));

	cout<<endl;

	wprintf_s(_T("%s\n"),String_Common(A,B));

	cout<<endl;

	wprintf_s(_T("%s\n"),String_Diff(A,B));

	return 0;
}


