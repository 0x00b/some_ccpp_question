/*********************************************************************
** 连续区间中的最大和
**
*********************************************************************/

#include "main.h"

#if _SECOND_NUM_

int MaxSum2(int *data, int n)
{
	int imax = data[0];
	int isum = 0;
	for (int i = 0; i < n; i++)
	{
		isum += data[i];
		if (isum < 0)
		{
			isum = 0;
		}
		if (isum > imax)
		{
			imax = isum;
		}
	}
	return imax;
}

int main()
{
	int arr[] = { 1,2,-4,5,6,3,-2,7,-8,9,-10,1 };
	int ret = 0;
	ret = MaxSum2(arr, 12);
	printf("连续的区间最大和：%d\n",ret);

#ifdef _WIN32
	return system("pause");
#else
	return 0;
#endif
}
#endif //_SECOND_NUM_
