
/*********************************************************************
** 在数组arr，一个数x，找出arr中两个数之和是x，或者没有这样的两个数
**
*********************************************************************/

#include "main.h"

#if _FIND_X_IN_ARR_

void quicksort(int a[], int n)
{
	int i = 0, j = n - 1;
	int temp = a[0];
	if (n > 1)
	{
		while (i<j)
		{
			while (i<j && a[j] >= temp)
			{
				j--;
			}
			a[i] = a[j];
			while (i<j && a[i] <= temp)
			{
				i++;
			}
			a[j] = a[i];
		}
		a[i] = temp;

		quicksort(a, i);
		quicksort(a + i + 1, n - i - 1);
	}
}

int find_x_(int a[], int n, int x)
{
	int sum = 0;
	int str = 0;
	int pos = 0;
	int end = n;
	/*
	//如果x处在数组比较中间的位置，数组也比较大的话，可以先来一趟快排，这样
	//只用在前个区间去找这两个数，因为明显一趟快排，x后面的数比他大，不会有和还会等于x
	int temp = x;
	int i = 0, j = n - 1;
	while (i < j)
	{
		while (i < j && a[j] >= temp)
		{
			j--;
		}
		a[i] = a[j];
		while (i < j && a[i] <= temp)
		{
			i++;
		}
		a[j] = a[i];
	}
	a[i] = temp;
	end = i; //只要从i前面找就好
	*/

	quicksort(a, end);
	
	for (size_t i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	pos = end - 1;
	while (str < pos)
	{
		sum = a[str] + a[pos];
		if (sum == x)
		{
			printf("\n%d %d\n", str , pos) ;
			//return pair(str,pos);
			return 0;
		}
		else if (sum < x)
		{
			str++;
		}
		else
		{
			pos--;
		}
	}

	return -1;
}

int main()
{
	int arr[] = { 11,3,9,7,5,13,20,15,25 };

	find_x_(arr, 9, 20);

#if defined(_WIN)
	return system("pause");
#else
	return 0;
#endif
}

#endif //_FIND_X_IN_ARR_