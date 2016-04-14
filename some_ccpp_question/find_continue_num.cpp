/*********************************************************************
** 找到一个字符串中最长的连续的数字
**
*********************************************************************/

#include "main.h"

#if _FIND_CON_NUM_

void Find(char* str, int* pos, int* len)
{
	int  iTemp, slen, iTempPos;
	*len = *pos = iTemp = iTempPos = 0;
	slen = strlen(str);
	for (int i = 0; i < slen - 1; i++)
	{
		if (str[i] > '0' && str[i] < '9'
			&& (str[i] - '0') == (str[i + 1] - '0' - 1))
		{
			iTemp++;
		}
		else
		{
			iTemp = 1;
			iTempPos = i + 1;
		}
		if (iTemp > *len)
		{
			*len = iTemp;
			*pos = iTempPos;
		}
	}


}


int main()
{
	int p, l;
	char str[] = "s12345sfds4567895t123456789";
	Find(str, &p, &l);
	printf("起始位置：%d ，一共有%d个\n", p, l);

#ifdef _WIN32
	return system("pause");
#else
	return 0;
#endif
}
#endif
