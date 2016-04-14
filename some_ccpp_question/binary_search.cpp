/*********************************************************************
** 二分查找
**  
*********************************************************************/

#include "main.h"

#if _BINARY_SEARCH_
/*
* 不用递归
*/
int binary_search_1(int* d, int n, int key)
{
	int low = 0, high = n - 1, mid;
	while (low <= high)
	{
		mid = low + ((high - low) >> 1);
		if (key == d[mid])
		{
			return mid;
		}
		if (key < d[mid])
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	return -1;
}
/*
* 递归的方式
*/
int binary_search_2(const int arr[], int low, int high, int key)
{
	int mid = low + (high - low) / 2;
	if (low>high)
		return-1;
	else {
		if (arr[mid] == key)
			return mid;
		else if (arr[mid]>key)
			return binary_search_2(arr, low, mid - 1, key);
		else
			return binary_search_2(arr, mid + 1, high, key);
	}
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	int ret = -1;
	ret = binary_search_1(arr, 9, 6);
	printf("binary_search_1:%d\n",ret);
	ret = -1;
	ret = binary_search_2(arr, 0, 8, 6); 
	printf("binary_search_2:%d\n", ret);

#ifdef _WIN32
	return system("pause");
#else
	return 0;
#endif
}

#endif //_BINARY_SEARCH_