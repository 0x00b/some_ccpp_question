/*********************************************************************
** 一个n*m的棋盘有p个棋子，找到其中不含棋子的最大矩形，返回面积
** eg: n = m = p = 3
** 1 1 1
** 0 0 0
** 0 0 0
**最大面积是 6
*********************************************************************/

#include "main.h"

#if _FIND_MAX_SQUARE_

#define MROW 100
int getMaxSquare(int a[MROW][MROW], int n, int m,int row, int col, int* max)
{
	int tmax = 0;

	bool bflag = false;
	//当前位置有棋子，则跳过
	if (0 == a[row][col])
	{
		//从当前位置往右边扫描，增加扫描的宽度 
		for (int i = col; i < m; i++)
		{
			if (a[row][i])
			{ 
				break; 
			}
			bflag = false;

			//当前宽度下面每一行的遇到棋子则跳出
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
			//当前宽度下面全是0
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
		//递归右边的位置
		getMaxSquare(a, n, m, row, col + 1, max);
	}
	else if (row < n)
	{
		//这一行已经扫描完了，下一行
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
