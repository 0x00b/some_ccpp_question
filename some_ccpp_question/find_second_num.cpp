/*********************************************************************
** �ҵ��ڶ������
** ��������ȡ�ڶ�������������ʱ�临�Ӷȴﲻ��O(N)
** �������򣬻���ð������һ�ο����ҵ�һ�����ģ���һ����������ڶ���ľͺá�
** ʱ�临�Ӷȿ��Կ�����O(N)
**
** ��չ���ҳ���k�������������λ�á�(ʱ�临�ӶȾ�����С)
**
*********************************************************************/

#include "main.h"

#if _FIND_SECOND_NUM_
/*
	�ҵ��ڶ��������
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
	�ҵ���k�������
	�����ȿ��š�Ȼ����ȡ
	���ַ���Ҫ�ǲ��ı�ԭ��������ݵĻ�����Ȼʱ�临�Ӷ���O(nlogn)
	���ǿռ临�Ӷ�ΪO(n)
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
�ҵ���k�������
�ȼ���������û���ظ���������ô�ź���֮���ǵ�k������Ҫ�ҵ�����
����ѡ�����򣬻���ð������ֻ��Ҫ��k�˾ͺ�

����ǿ�������Ļ���

	�ٸ����ӣ� ������Ҫ�ҵ����ǵ��Ĵ������
	Ҳ���������3.����ʽ�Ӵ�С
	3 2 5 7 8 1
	һ������
	8 7 5 3 2 1
	����3�����ڵ�4��λ�ã���ô3����Ҫ�ҵ��������ַ���ĳ�̶ֳ����ǲ���Ҫ��һ���أ�
	���ı�ԭ������������Ҫ����O(N)�Ŀռ������򡣡�
*/

int FKN_quiksort(int a[], int str, int end, int k);
int FindKthNum_2(int a[], int n, int k)
{
	int pos = -1;
	int* arr = (int*)malloc(n * sizeof(int));
	memcpy(arr, a, n*sizeof(int));
	//�ҵ���k�����
	int num = FKN_quiksort(arr, 0, n - 1, k);
	if (num == -1)
	{
		return -1;
	}
	//�ҵ���k�������λ��
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
	����ʲô�취�ܲ���ҪO(N)�ռ��أ�
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
	printf("input some numbers(first is count ,count < 20)��\n");
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
		while (i < j)//һ������ȷ�����ᣬ������a[0]��λ�ã������С�ڵ��������ұߴ��ڵ�������������ȵĲ��Ż�
		{
			while (i < j && a[j] >= temp)//�ұ���С��������Ȳ���
			{
				j--;
			}
			a[i] = a[j];
			while (i < j && a[i] <= temp)//����Ҵ��������Ȳ���
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
	if (i == (k - 1))//�ҵ���,�ҵ�֮ǰ�����������̣�λ�ÿ��ܸı䣬�������ҵ�����������ǲ����ҵ�ԭ��λ��
	{
		return a[i];
	}
	else
	{
		if (k < i)//ȷ����Ѱ��������仹���ұ�����
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