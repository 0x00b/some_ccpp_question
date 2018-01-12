/*********************************************************************
** һ�������У��ҵ������������������������е�����
** eg: -1 3 -1 3 -10 2 -1  res: [3-1+3] + [2] = 7
*********************************************************************/

#include "main.h"

#if _TWO_PART_MAX_

//�ҵ�һ�����������䣬�������ĺ�����������������ĺ͵����ֵ
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
	//���ҵ�һ����������
	int max = MaxSum2(a, n, &start, &end);
	printf("1:%d %d %d\n",max, start, end);
	int start_t, end_t;
	bool bfind = false;
	
	// �ҵ�һ����������֮�󣬰����黮�ֳ��������֣��ٴ����������ҵ��������������������ֵ
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


	//���Ѿ��ҵ����������������У��ҵ���С��ֵ��ϣ���Ǹ�ֵ����ȥ���߽磬�߽粻�����Ǹ�����
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
		//�ܹ��ҵ�������������������ֵ�����нϴ��һ�����û��һ��ʼ�ҵ�������������������С���Ǹ�����Ӱ���
		//��ô���Ǹ�������ԭ������������һ��Ϊ������
		int max_t = (max1 > max2 ? max1 : max2);
		if (min < 0 && (min + max_t) < 0)
		{
			return max - min;
		}
		//���û������������û�и�������ôֱ�Ӽ������������������е��������ֵ����������
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
	printf("�������������ͣ�%d\n", ret);

#if defined(_WIN)
	return system("pause");
#else
	return 0;
#endif
}
#endif //_SECOND_NUM_
