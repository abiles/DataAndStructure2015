// ActivitySelection.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

struct Activity
{
	int start = 0;
	int end = 0;
};

int ActivityGreedyIter(Activity* actArr, int size)
{
	if (!actArr || size <= 0) return 0;

	int count = 0;
	int curEnd = 0;

	for (int i = 0; i < size; ++i)
	{
		if (curEnd < actArr[i].start)
		{
			++count;
			curEnd = actArr[i].end;
		}
	}

	return count;
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

