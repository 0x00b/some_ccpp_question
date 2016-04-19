/*********************************************************************
** �ҵ��ڶ������
** ��������ȡ�ڶ�������������ʱ�临�Ӷȴﲻ��O(N)
** �������򣬻���ð������һ�ο����ҵ�һ�����ģ���һ����������ڶ���ľͺá�
** ʱ�临�Ӷȿ��Կ�����O(N)
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
	printf("input some numbers(first is count ,count < 20)��\n");
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