/*
* 将一个数分解成几个连续的数，
* 比如
*  12 = 3 + 4 + 5
*  15 = 7 + 8 = 4 + 5 + 6 = 1 + 2 + 3+ 4 + 5
* 
*  我发现2^n不能分解成这样连续的数相加。这个数学上应该是可以证明的
*/

#include "main.h"

#if _DECOMPOSE_SUCCESSIVE_NUM_

void FindSuccessiveNum(int n)
{
	int str = 1, end = 1, sum = 1;
	while (end < n)
	{
		if (sum > n)
		{
			sum -= str;
			str++;
		}
		if (sum < n)
		{
			sum += ++end;
		}
		if (sum == n)
		{
			printf("%d = %d", n, str);
			for (int j = str + 1; j <= end; j++)
			{
				printf(" + %d ", j);
			}
			printf("\n");
			sum -= str;
			str++;
		}

	}
}

int main(int argc, char* args[])
{
	int n = 15;
	if (argc > 1)
	{
		n = atoi(args[1]);
		printf("%d successive num is:\n", n);
		FindSuccessiveNum(n);
	}
	else
	{
		for (int i = 3; i < 257; i++)
		{
			printf("%d successive num is:\n", i);
			FindSuccessiveNum(i);
		}
	}

#if defined(_WIN)
	return system("pause");
#else
	return 0;
#endif
	}

#endif _DECOMPOSE_SUCCESSIVE_NUM_