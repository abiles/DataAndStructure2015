// Fibonacci.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

int fibo(int n)
{
	if (n < 2) return n;
	return fibo(n - 1) + fibo(n - 2);
}

// n+1 크기의 arr가 필요함
int fiboTopDown(int n, int* arr)
{
	if (arr[n] != -1) return arr[n];

	if (n < 2)
	{
		arr[n] = n;
		return arr[n];
	}
	else
	{
		return fiboTopDown(n - 1, arr) + fiboTopDown(n - 2, arr);
	}
}

int fiboBottomUp(int n)
{
	if (n < 0) return -1;

	int* arr = new int[n + 1];

	arr[0] = 0;
	arr[1] = 1;

	for (int i = 2; i <= n; ++i)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}

	int result = arr[n];

	delete[] arr;

	return result;
}



int _tmain(int argc, _TCHAR* argv[])
{
	int seed = 5;

	printf_s("fibo : %d\n", fibo(seed));

	int* arr = new int[seed + 1];

	for (int i = 0; i <= seed; ++i)
	{
		arr[i] = -1;
	}

	printf_s("fiboTopDown : %d\n", fiboTopDown(seed, arr));

	printf_s("fiboBottomUP : %d\n", fiboBottomUp(seed));

	getchar();
	getchar();

	delete[] arr;

	return 0;
}

