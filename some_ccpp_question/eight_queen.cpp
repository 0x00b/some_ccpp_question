#include "main.h"

#if _EIGHT_QUEEN_

#define EDGE 8

int chessboard[EDGE][EDGE];

void print()
{
	for (int i = 0; i < EDGE; i++)
	{
		for (int j = 0; j < EDGE; j++)
		{
			printf("%d ",chessboard[i][j]);
		}
		printf("\n");
	}
	printf("\n");

}

/* 解法一：
 * 最简单的办法，穷举法，列举所有的放法，然后一个一个判断是否符合要求 */

/* 逐行往下放，所以新放的皇后只会在她上面的行，所以只要往之上的行判断 
* 例如 :下面*的位置如果新放一颗棋子，则需要判断的三个方向
*
*  1 0 0 \ 0 0 | 0 
*  0 0 1 0 \ 0 | 0
*  0 0 0 0 1 \ | /
*  0 0 0 0 0 0 * 0
*
*/
int judge(int row, int col) 
{
	/* 同一列 */
	for (int i = 0; i < row; i++)
	{
		if (chessboard[i][col] == 1)
		{
			return 0;
		}

	}
	/* \ 方向 */
	for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--,j--)
	{
		if (chessboard[i][j] == 1)
		{
			return 0;
		}
	}

	/* / 方向 */
	for (int i = row - 1, j = col + 1; i >= 0 && j < EDGE; i--, j++)
	{
		if (chessboard[i][j] == 1)
		{
			return 0;
		}
	}
	return 1;
}

int eight_queen_1()
{
	int sum = 0;
	for (int i = 0; i < EDGE; i++)
	{
		for (int j = 0; j < EDGE; j++)
		{
			chessboard[i][j] = 0;
		}
	}

	for (int first = 0; first < EDGE; first++)
	{
		chessboard[0][first] = 1;
		for (int second = 0; second < EDGE; second++)
		{
			chessboard[1][second] = 1;
			/* 每放一个棋子，就判断和之前放的棋子有没有冲突，有的话就没有必要放下面的棋子了，需要在这一行找其他的位置*/
			if (judge(1, second))
			{
				for (int third = 0; third < EDGE; third++)
				{
					chessboard[2][third] = 1;
					/* 与上个judge的功能一样，以此类推 */
					if (judge(2, third))
					{
						for (int fourth = 0; fourth < EDGE; fourth++)
						{
							chessboard[3][fourth] = 1;
							if (judge(3, fourth))
							{
								for (int fifth = 0; fifth < EDGE; fifth++)
								{
									chessboard[4][fifth] = 1;
									if (judge(4, fifth))
									{
										for (int sixth = 0; sixth < EDGE; sixth++)
										{
											chessboard[5][sixth] = 1;
											if (judge(5, sixth))
											{
												for (int seventh = 0; seventh < EDGE; seventh++)
												{
													chessboard[6][seventh] = 1;
													if (judge(6, seventh))
													{
														for (int eighth = 0; eighth < EDGE; eighth++)
														{
															chessboard[7][eighth] = 1;

															if (judge(7, eighth))
															{
																/* 最后一个棋子和之前的棋子都不冲突，就找到一种解*/
																sum++;
																printf("%d %d %d %d %d %d %d %d\n", first + 1, second + 1, third + 1
																	, fourth + 1, fifth + 1, sixth + 1, seventh + 1, eighth + 1);
																//print();
															}

															chessboard[7][eighth] = 0;
														}
													}
													chessboard[6][seventh] = 0;
												}
											}
											chessboard[5][sixth] = 0;
										}
									}
									chessboard[4][fifth] = 0;
								}
							}
							chessboard[3][fourth] = 0;
						}
					}
					chessboard[2][third] = 0;
				}
			}
			chessboard[1][second] = 0;
		}
		chessboard[0][first] = 0;
	}
	return sum;
}


/*解法二：
* 回溯法
*/

/* queens[i] 表示第i颗棋子的列坐标 */
int queens[EDGE];
/*
* queens[0]=1  1 0 0 0 0 0 0 0 
* queens[1]=3  0 0 3 0 0 0 0 0
* queens[2]=5  0 0 0 0 5 0 0 0
*  .....
* queens[7]=8  0 0 0 0 0 0 0 8
*/

void init_queens()
{
	for (int i = 0; i < EDGE; i++)
	{
		queens[i] = 0;
	}
}

/*index: 表示第index颗棋子
* col  : 表示第index颗棋子在这一行的第几列
*/
int check(int index, int col) 
{
	for (int i = 0; i < index; i++)
	{
		if (queens[i] == col   /* 同一列 */
			|| queens[i] == col - (index - i)   /* \方向  */
			|| queens[i] == col + (index - i)   /* /方向  */)
		{
			return 0;
		}
	}
	return 1;
}

int sum = 0;

void eight_queen_2(int index)
{
	for (int i = 0; i < EDGE; i++)
	{
		if (check(index, i + 1))
		{
			queens[index] = i + 1;
			if (index == EDGE - 1)
			{/* 最后一颗棋子 */
				sum++;
				return;
			}
			eight_queen_2(index + 1);
			queens[index] = 0;
		}
	}
}

int main()
{

	//printf("八皇后问题共有%d种解",eight_queen_1());
	
	init_queens();
	eight_queen_2(0);

	printf("八皇后问题共有%d种解", sum);

#if defined(_WIN)
	return system("pause");
#else
	return 0;
#endif
}
#endif // JOSEPH
