
#include "main.h"

#if _PREMIDTOAFTER_


int departmid(char root, char* mid)
{
	int i = 0;
	while (mid[i] != 0)
	{
		if (root == mid[i])
		{
			return i;
		}
		i++;
	}
	return -1;
}

void premidtoafter(char* pre, char* mid, char* aft,int& n)
{
	int m = departmid(pre[0], mid);
	if (m == -1)
	{
		return;
	}
	aft[n++] = pre[0];
	char str[100];
	ZeroMemory(str,100);
	strncpy(str, mid , m);
	str[m + 1] = 0;
	premidtoafter(pre + 1 + m, mid + m + 1 , aft, n);
	premidtoafter(pre + 1, str, aft, n);
}

int main()
{
	char str1[100] = "ABDECFG";
	char str2[100] = "DBEACGF";
	char aft[100];
	ZeroMemory(aft,100);
	int n = 0;
	premidtoafter(str1, str2, aft,n);
	printf("Ç°Ğò£º%s\n", str1);
	printf("ÖĞĞò£º%s\n", str2);
	printf("ºóĞò£º");
	for (int i = n-1; i >= 0; i--)
	{
		printf("%c",aft[i]);
	}

	printf("\n");

#if defined(_WIN)
	return system("pause");
#else
	return 0;
#endif
}
#endif