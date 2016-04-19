/*********************************************************************
** 找到第二大的数
** 可以排序取第二个。但是排序时间复杂度达不到O(N)
** 插入排序，或者冒泡排序一次可以找到一个最大的，加一个变量保存第二大的就好。
** 时间复杂度可以控制在O(N)
**
*********************************************************************/

#include "main.h"

#if _FIND_SECOND_NUM_

int FindSecondNum(int* arr, int n)
{
	int max, scnd;
	max = 0;
	scnd = -1;
	for (int i = 1; i < n; i++)
	{
		if (arr[max] < arr[i])
		{
			scnd = max;
			max = i;
		}
		else if (arr[scnd] < arr[i])
		{
			scnd = i;
		}
	}
	return scnd;
}


int main()
{
	int arr[20];
	int n = 0;
	int ret = -1;
	printf("input some numbers(first is count ,count < 20)：\n");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	ret = FindSecondNum(arr, n);
	if (-1 == ret )
	{
		printf("nothing to find\n");
		return 0;
	}
	printf("the second num %d , pos is:%d\n", arr[ret], ret);


#if defined(_WIN)
	return system("pause");
#else
	return 0;
#endif
}


#endif // _FIND_SECOND_NUM_