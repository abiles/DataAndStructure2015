// LogestCommonSub.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;


// curPos�� 0���� ����
string LongestCommonSub(string& strA, int curAPos, string& strB, int curBPos, string result)
{
	if (curAPos == strA.size() || curBPos == strB.size()) return result;

	
	if (strA[curAPos] == strB[curBPos])
	{
		result += strA[curAPos];
		return LongestCommonSub(strA, curAPos + 1, strB, curBPos + 1, result);
	}
	else
	{
		string tmp1 = LongestCommonSub(strA, curAPos + 1, strB, curBPos, result);
		string tmp2 = LongestCommonSub(strA, curAPos, strB, curBPos + 1, result);

		if (tmp1.size() > tmp2.size())
		{
			return tmp1;
		}
		else
		{
			return tmp2;
		}
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	string a = "NorthKorea";
	string b = "SouthKorea";

	string result;
	result = LongestCommonSub(a, 0, b, 0, result);

	cout << result << endl;

	getchar();
	getchar();

	return 0;
}

