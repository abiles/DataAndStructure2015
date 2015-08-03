// MatrixChain.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

struct Matrix
{
	int row = 0;
	int column = 0;
};

int GetMinCost(Matrix* matrices, int startId, int endId)
{
	if (startId == endId) return 0;

	int min = INT_MAX;
	int tmp = 0;

	for (int indexOfCurPos = startId; indexOfCurPos < endId; ++indexOfCurPos)
	{
		tmp = GetMinCost(matrices, startId, indexOfCurPos) +
			GetMinCost(matrices, indexOfCurPos + 1, endId) +
			matrices[startId].row * matrices[indexOfCurPos].column * matrices[endId].column;

		if (tmp < min)
			min = tmp;
	}

	return min;
}

int GetMinCostByMeMorization(Matrix* matrices, int startId, int endId, int** resultMaxtrix)
{
	if (resultMaxtrix[startId][endId] != -1) return resultMaxtrix[startId][endId];

	if (startId == endId)
	{
		resultMaxtrix[startId][endId] = 0;
		return 0;
	}

	int min = INT_MAX;
	int tmp = 0;

	for (int indexOfCurPos = startId; indexOfCurPos < endId; ++indexOfCurPos)
	{
		tmp = GetMinCostByMeMorization(matrices, startId, indexOfCurPos, resultMaxtrix) +
			GetMinCostByMeMorization(matrices, indexOfCurPos + 1, endId, resultMaxtrix) +
			matrices[startId].row * matrices[indexOfCurPos].column * matrices[endId].row;

		if (tmp < min)
		{
			min = tmp;
			resultMaxtrix[startId][endId] = min;
		}
			
	}

	return resultMaxtrix[startId][endId];
}

int _tmain(int argc, _TCHAR* argv[])
{
	Matrix matrices[10];

	//예제 만들어 주기

	

	return 0;
}

