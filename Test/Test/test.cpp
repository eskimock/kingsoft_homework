// test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


void print_str(const char& s)  
{  
	cout<<s<<endl;  
} 



//查找最大公共子串
CString GetMaxCommonStr(CString& A,CString& B)
{
	CString strA = A;
	CString strB = B;
	if(strA.GetLength() < strB.GetLength())
	{
		CString strTemp = strA;
		strA = strB;
		strB = strTemp;
	}

	int ilen = 0;
	int iend = 0;
	int* flag = new int[strA.GetLength()];

	for(int iB = 0;iB < strB.GetLength();iB++)
	{
		for(int iA = strA.GetLength() - 1;iA >= 0;iA--)
		{
			if(strA[iA] == strB[iB])
			{
				if((iA == 0)||(iB == 0))
				{
					flag[iA] = 1;
				}
				else
				{
					flag[iA] = flag[iA - 1] + 1;
				}
			}
			else
				flag[iA] = 0;

			if(flag[iA] > ilen)
			{
				ilen = flag[iA];
				iend = iA;
			}
		}
	}

	delete[] flag;
	flag = NULL;

	return strA.Mid(iend - ilen + 1,ilen);
}

//务必确保A和B的最大公共子串为空
CString GetFilledStr(const CString& strA,const CString& strB)
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


CString String_Diff(CString& strA,CString& strB)
{
	/*static*/ CString strRes;
	CString strTempCommon = GetMaxCommonStr(strA,strB);

	if(strTempCommon == _T(""))
	{
		strRes += GetFilledStr(strA,strB);
		return strRes;
	}
	else
	{
		CString sA1 = strA.Left(strA.Find(strTempCommon));
		CString sB1 = strB.Left(strB.Find(strTempCommon));
		String_Diff(sA1,sB1);

		strRes += strTempCommon;
		strRes += _T("(=)");

		CString sA2 = strA.Right(strA.GetLength() - strTempCommon.GetLength() - strA.Find(strTempCommon));
		CString sB2 = strB.Right(strB.GetLength() - strTempCommon.GetLength() - strB.Find(strTempCommon));

		String_Diff(sA2,sB2);
			
	}

	
}

int _tmain(int argc, _TCHAR* argv[])
{
	CString A(_T("klsajhjdf"));
	CString B(_T("dskajf"));

	wprintf_s(_T("%s\n"),GetFilledStr(A,B));

	cout<<endl;

	wprintf_s(_T("%s\n"),GetMaxCommonStr(A,B));

	cout<<endl;

	wprintf_s(_T("%s\n"),String_Diff(A,B));
	return 0;
}

