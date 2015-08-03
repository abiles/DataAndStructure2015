// KnapSack.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int doubleMaxtrix[2][3] = {
	{ 1, 2, 3 },
	{ 4, 5, 6 },

};

int GetMaxRecursive(int* value, int* weight, int inputableWeight, int curIdx, int size)
{
	if (curIdx >= size) return 0;
	
	int tmpValue = 0;
	
	if (weight[curIdx] <= inputableWeight)
	{
		tmpValue = value[curIdx] + GetMaxRecursive(value, weight, inputableWeight - weight[curIdx], curIdx + 1, size);
	}

	int tmpValue2 = GetMaxRecursive(value, weight, inputableWeight, curIdx + 1, size);

	if (tmpValue > tmpValue2)
	{
		return tmpValue;
	}
	else
	{
		return tmpValue2;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	
	int value[] = { 1, 2, 4, 7, 20 };
	int weight[] = { 1, 2, 3, 4, 5 };
	int inputableWeight = 10;

	int size = sizeof(value) / sizeof(value[0]);
	printf_s("maxVale : %d\n", GetMaxRecursive(value, weight, inputableWeight, 0, size));

	printf_s("\n");

	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			printf_s("%d", doubleMaxtrix[i][j]);
		}
		printf_s("\n");
	}

	getchar();
	getchar();

	return 0;
}

