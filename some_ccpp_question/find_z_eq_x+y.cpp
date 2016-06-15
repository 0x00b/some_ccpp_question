
/*********************************************************************
** ������arr��һ����x���ҳ�arr��������֮����x������û��������������
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
	//���x��������Ƚ��м��λ�ã�����Ҳ�Ƚϴ�Ļ�����������һ�˿��ţ�����
	//ֻ����ǰ������ȥ��������������Ϊ����һ�˿��ţ�x������������󣬲����кͻ������x
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
	end = i; //ֻҪ��iǰ���Ҿͺ�
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