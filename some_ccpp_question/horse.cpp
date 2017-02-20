#include "main.h"

#if _HORSE_

#define EDGE 5

int chessboard[EDGE][EDGE];
int flag[EDGE][EDGE];

void init()
{
	int t = 1;
	for (int i = 0; i < EDGE; i++)
	{
		for (int j = 0; j < EDGE; j++)
		{
			chessboard[i][j] = t++;
			flag[i][j] = 0;
		}
	}
}
int steps[26];
int sum = 0;
int dir[8][2] = { {-2,-1},{-2,+1},{-1,+2},{+1,+2},{+2,+1},{+2,-1},{+1,-2},{-1,-2} };
void horse(int step, int row, int col)
{
	int nx = 0, ny = 0;
	flag[row][col] = 1;/* 标记当前位置为已走过*/
	steps[step] = chessboard[row][col];/* 记录路径*/

	/* 寻找下一个位置*/
	for (int i = 0; i < 8; i++)
	{
		nx = row + dir[i][0];
		ny = col + dir[i][1];
		if (nx < EDGE&&nx >= 0 && ny < EDGE&&ny >= 0)
		{
			if (flag[nx][ny] == 0)
			{
				/* 这个位置可以走 */
				horse(step + 1, nx, ny);
				/* 这个位置走过了回溯的时候需要标为没走过*/
				flag[nx][ny] = 0;
			}
		}
	}
	if (step == 25)/* 走了25步说明走完棋盘了 */
	{
		sum++;
		for (int i = 1; i < 26; i++)
		{
			printf("[%d,%d]->",i,steps[i]);
		}
		printf("\n");
	}
}

int main()
{
	init();
	horse(1, 0, 0);
	printf("共有%d种\n",sum);
#if defined(_WIN)
	return system("pause");
#else
	return 0;
#endif
}
#endif // JOSEPH