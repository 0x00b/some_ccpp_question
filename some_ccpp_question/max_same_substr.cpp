
#include "main.h"

#if _MAX_SAME_SUBSTR_

void maxsamesubstr(char* str1, char* str2)
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);

	int k = 0, m = 0, n = 0;
	int start = 0, len = 0;
	int tstart = 0, tlen = 0;
	for (int i = 0; i < len1; i++)
	{
		for (int j = 0; j < len2; j++)
		{
			m = i;
			n = j;
			while (str1[m] != 0 && str2[n] != 0 && str1[m++] == str2[n++])
			{
				if (tlen == 0)
				{
					tstart = m;
				}
				tlen++;
			}
			if (tlen > len)
			{
				len = tlen;
				start = tstart;
			}
			tlen = 0;
		}
	}
	char str[100];
	strncpy(str, str1 + start - 1, len);
	str[ len ] = '\0';
	printf("相同子串为：%s（长度%d）", str, len);
}

int main()
{
	char str1[100] = "bzxcvbnmasd";
	char str2[100] = "aaazxcvbncccc";
	maxsamesubstr(str1, str2);
#if defined(_WIN)
	return system("pause");
#else
	return 0;
#endif
}
#endif