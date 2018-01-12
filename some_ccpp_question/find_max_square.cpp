/*********************************************************************
** һ��n*m��������p�����ӣ��ҵ����в������ӵ������Σ��������
** eg: n = m = p = 3
** 1 1 1
** 0 0 0
** 0 0 0
**�������� 6
*********************************************************************/

#include "main.h"

#if _FIND_MAX_SQUARE_

#define MROW 100
int getMaxSquare(int a[MROW][MROW], int n, int m,int row, int col, int* max)
{
	int tmax = 0;

	bool bflag = false;
	//��ǰλ�������ӣ�������
	if (0 == a[row][col])
	{
		//�ӵ�ǰλ�����ұ�ɨ�裬����ɨ��Ŀ�� 
		for (int i = col; i < m; i++)
		{
			if (a[row][i])
			{ 
				break; 
			}
			bflag = false;

			//��ǰ�������ÿһ�е���������������
			for (int j = row + 1; j < n; j++)
			{
				for (int k = col; k <= i; k++)
				{
					if (a[j][k])
					{
						tmax = (j - row)*(i - col + 1);
						
						if (tmax > *max)
						{
							*max = tmax;
						}
						bflag = true;
						break;
					}
				}
				if (bflag)
				{
					break;
				}
			}
			//��ǰ�������ȫ��0
			if (!bflag)
			{
				tmax = (n - row)*(i - col + 1);
				if (tmax > *max)
				{
					*max = tmax;
				}
			}
		}
	}
	
	if (col < m)
	{
		//�ݹ��ұߵ�λ��
		getMaxSquare(a, n, m, row, col + 1, max);
	}
	else if (row < n)
	{
		//��һ���Ѿ�ɨ�����ˣ���һ��
		getMaxSquare(a, n, m, row + 1, 0, max);
	}

	return *max;
}

int main()
{
	int a[MROW][MROW] = { 
		{1,1,0,0},
		{0,1,0,0},
		{0,0,1,0},
		{0,0,0,1} };

	int max = 0;

	getMaxSquare(a, 4, 4, 0, 0, &max);

	printf("max:%d\n", max);

#if defined(_WIN)
	return system("pause");
#else
	return 0;
#endif
}
#endif //_SECOND_NUM_
