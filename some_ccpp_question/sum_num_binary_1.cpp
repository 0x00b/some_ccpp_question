#include "main.h"

#if _SUM_NUM_BIN_1_
int count(int n)
{
	int sum = 0;
	while (n)
	{
		sum++;
		n = n&(n - 1);
	}
	return sum;
}

int main()
{
	int n = 222;
	int ret = count(n);

	printf("%d的二进制中有%d个1\n", n, ret);


#ifdef _WIN32
	return system("pause");
#else
	return 0;
#endif
}
#endif //_SUM_NUM_BIN_1_