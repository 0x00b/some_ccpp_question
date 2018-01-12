/*********************************************************************
** 一个数组中，找到两个不相邻连续区间区间中的最大和
** eg: -1 3 -1 3 -10 2 -1  res: [3-1+3] + [2] = 7
*********************************************************************/

#include "main.h"

#if _TWO_PART_MAX_

//找到一个连续的区间，这个区间的和是所有连续子区间的和的最大值
int MaxSum2(int *data, int n,int* start, int* end)
{
	int imax = data[0];
	int isum = 0;
	*start = 0;
	*end = 0;
	int start_t = 0;
	for (int i = 0; i < n; i++)
	{
		isum += data[i];
		if (isum < 0)
		{
			isum = 0;
			start_t = i + 1;
		}
		if (isum > imax)
		{
			imax = isum;
			*end = i;
			*start = start_t;
		}
	}
	return imax;
}

int GetTwoPartMax(int a[], int n)
{
	int start = 0, end = 0;
	int max1=0, max2=0;
	//先找到一个连续区间
	int max = MaxSum2(a, n, &start, &end);
	printf("1:%d %d %d\n",max, start, end);
	int start_t, end_t;
	bool bfind = false;
	
	// 找到一个连续区间之后，把数组划分成三个部分，再从其他部分找到另外两个连续区间最大值
	if (start > 1)
	{
		max1 = MaxSum2(a, start, &start_t, &end_t);
		printf("2:%d %d %d\n", max1, start_t, end_t);
		bfind = true;
	}
	if (end < n - 1)
	{
		max2 = MaxSum2(a + end + 1, n - end - 1, &start_t, &end_t);
		printf("3:%d %d %d\n", max2, start_t, end_t);
		bfind = true;
	}


	//从已经找到连续和最大的区间中，找到最小的值（希望是负值），去除边界，边界不可能是负数，
	int min = 0;
	int min_pos = 0;
	if ((start + 1) < (end))
	{
		min = a[start + 1];
		min_pos = start + 1;
		for (int i = start + 2; i < end; i++)
		{
			if (min > a[i])
			{
				min = a[i];
				min_pos = i;
			}
		}
		printf("4:%d %d\n", min, min_pos);
	}

	if (bfind)
	{
		//能够找到另外两个子区间的最大值，其中较大的一个如果没有一开始找到的连续区间最大和中最小的那个负数影响大，
		//那么用那个负数把原来的连续区间一分为二即可
		int max_t = (max1 > max2 ? max1 : max2);
		if (min < 0 && (min + max_t) < 0)
		{
			return max - min;
		}
		//如果没有连续区间中没有负数，那么直接加上另外两个子区间中的连续最大值就是所求结果
		return (max + max_t);
	}
	else
	{
		return (max - min);
	}
	return 0;
}

int main()
{
	int arr[] = { 1,2,4,5,6,3,-2,7,-8,9,-10,1 };
	//int arr[] = { -1,3,-1, 3,-10, 2,-1};
	int ret = 0;
	ret = GetTwoPartMax(arr, sizeof(arr) / sizeof(int));
	printf("连续的区间最大和：%d\n", ret);

#if defined(_WIN)
	return system("pause");
#else
	return 0;
#endif
}
#endif //_SECOND_NUM_
