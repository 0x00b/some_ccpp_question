/*********************************************************************
** 找到第二大的数
** 可以排序取第二个。但是排序时间复杂度达不到O(N)
** 插入排序，或者冒泡排序一次可以找到一个最大的，加一个变量保存第二大的就好。
** 时间复杂度可以控制在O(N)
**
** 扩展：找出第k大的数，返回其位置。(时间复杂度尽可能小)
**
*********************************************************************/

#include "main.h"

#if _FIND_SECOND_NUM_
/*
	找到第二大的数，
*/
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

/*
	找到第k大的数：
	可以先快排。然后再取
	这种方法要是不改变原数组的内容的话，虽然时间复杂度是O(nlogn)
	但是空间复杂度为O(n)
*/
void quiksort(int a[], int n);
int FindKthNum_1(int a[], int n, int k)
{
	int pos = -1;
	int* arr = (int*)malloc(n * sizeof(int));
	memcpy(arr, a, n*sizeof(int));
	quiksort(arr, n);
	for (pos = 0; pos < n; pos++)
	{
		if (a[pos] == arr[n - k])
		{
			break;
		}
	}
	free(arr);
	return pos;
}

/*
找到第k大的数：
先假设数组中没有重复的数，那么排好序之后是第k个就是要找的数。
所以选择排序，或者冒泡排序只需要排k趟就好

如果是快速排序的话？

	举个例子， 假设我要找的数是第四大的数，
	也就是这里的3.排序方式从大到小
	3 2 5 7 8 1
	一趟排序
	8 7 5 3 2 1
	发现3正好在第4个位置，那么3就是要找的数，这种方法某种程度上是不是要快一点呢？
	不改变原数组的情况还是要借助O(N)的空间来排序。。
*/

int FKN_quiksort(int a[], int str, int end, int k);
int FindKthNum_2(int a[], int n, int k)
{
	int pos = -1;
	int* arr = (int*)malloc(n * sizeof(int));
	memcpy(arr, a, n*sizeof(int));
	//找到第k大的数
	int num = FKN_quiksort(arr, 0, n - 1, k);
	if (num == -1)
	{
		return -1;
	}
	//找到第k大的数的位置
	for (int i = 0; i < n; i++)
	{
		if (a[i] == num)
		{
			pos = i;
			break;
		}
	}
	free(arr);
	return pos;
}

/*
	还有什么办法能不需要O(N)空间呢？
*/
int FindKthNum_3(int a[], int n, int k)
{
	//add code

	return -1;
}


int main()
{
	int arr[20];
	int n = 0;
	int k = 0;
	int ret = -1;
	printf("input some numbers(first is count ,count < 20)：\n");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	ret = FindSecondNum(arr, n);
	if (-1 == ret)
	{
		printf("nothing to find\n");
		return 0;
	}
	printf("the second num %d , pos is:%d\n", arr[ret], ret);
	printf("input you want Kth num:");
	scanf("%d", &k);
	printf("FindKthNum_1:");
	int pos = FindKthNum_1(arr, n, k);
	printf("%dth = %d pos = %d\n", k, arr[pos], pos);

	printf("FindKthNum_2:");
	pos = FindKthNum_2(arr, n, k);
	printf("%dth = %d pos = %d\n", k, arr[pos], pos);

#if defined(_WIN)
	return system("pause");
#else
	return 0;
#endif
}

void quiksort(int a[], int n)
{
	int i = 0, j = n - 1;
	int temp = a[0];
	if (n > 1)
	{
		while (i < j)//一趟排序，确定枢轴，这里是a[0]的位置，他左边小于等于他，右边大于等于他。对于相等的不优化
		{
			while (i < j && a[j] >= temp)//右边找小的数，相等不管
			{
				j--;
			}
			a[i] = a[j];
			while (i < j && a[i] <= temp)//左边找大的数，相等不管
			{
				i++;
			}
			a[j] = a[i];
		}
		a[i] = temp;
		quiksort(a, i);
		quiksort(a + i + 1, n - i - 1);
	}
}


int FKN_quiksort(int a[], int str, int end, int k)
{
	int temp = a[str];
	int i = str, j = end;

	while (i < j)
	{
		while (i < j && a[j] <= temp)
		{
			j--;
		}
		a[i] = a[j];
		while (i < j && a[i] >= temp)
		{
			i++;
		}
		a[j] = a[i];
	}
	a[i] = temp;
	if (i == (k - 1))//找到了,找到之前如果有排序过程，位置可能改变，所以能找到这个数，但是不能找到原来位置
	{
		return a[i];
	}
	else
	{
		if (k < i)//确定是寻找左边区间还是右边区间
		{
			return FKN_quiksort(a, 0, i - 1, k);
		}
		else
		{
			return FKN_quiksort(a, i + 1, end, k);
		}
	}
	return -1;
}

#endif // _FIND_SECOND_NUM_