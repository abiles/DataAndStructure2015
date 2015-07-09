// RodCutting.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

int valueArr[] = {0, 1, 5, 10, 2, 1 };


int GetMaxValue(int* valueArr, int n)
{
	int maxValue = 0;
	int tmpValue = 0;

	for (int i = 1; i <= n; ++i)
	{
		tmpValue = valueArr[i] + GetMaxValue(valueArr, n- i);

		if (tmpValue > maxValue)
			maxValue = tmpValue;
	}

	return maxValue;
}

int GetMaxValueTopDown(int* valueArr, int* resultArr, int n)
{
	if (resultArr[n] != -1) return resultArr[n];

	int maxValue = 0;
	int tmpValue = 0;

	for (int i = 1; i <= n; ++i)
	{
		tmpValue = valueArr[i] + GetMaxValueTopDown(valueArr, resultArr, n - i);

		if (maxValue < tmpValue)
		{
			maxValue = tmpValue;
		}
	}

	resultArr[n] = maxValue;

	return maxValue;
}

int GetMaxBottomUp(int* arr, int n)
{
	int* resultArr = new int[n+1];

	for (int i = 0; i <= n; ++i)
	{
		resultArr[i] = 0;
	}

	int maxValue = 0;
	int tmpValue = 0;

	for (int i = 1; i <= n; ++i)
	{
		maxValue = 0;

		for (int j = 1; j <= n; j++)
		{
			tmpValue = arr[i] + resultArr[n - i];

			if (tmpValue > maxValue)
			{
				maxValue = tmpValue;
			}
		}
		resultArr[i] = maxValue;
	}

	return resultArr[n];
}


int _tmain(int argc, _TCHAR* argv[])
{
	int valueArrSize = sizeof(valueArr) / sizeof(valueArr[0]) -1;

	printf_s("maxValue = %d\n", GetMaxValue(valueArr, valueArrSize));

	int* resultArr = new int[valueArrSize];

	for (int i = 0; i <= valueArrSize; ++i)
	{
		resultArr[i] = -1;
	}
	printf_s("maxValue With TopDown = %d\n", GetMaxValueTopDown(valueArr, resultArr, valueArrSize));

	getchar();
	getchar();

	delete[] resultArr;

	return 0;
}

