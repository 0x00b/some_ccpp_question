
#include "main.h"

#if _IS_BIG_ENDIAN_

int isBigEndian()
{
	unsigned short i = 1;
	return *(unsigned char*)(&i) != 0x01;
}

int main()
{
	printf("����ϵͳ��:%s\n", isBigEndian() ? "���" : "С��");

#ifdef _WIN32
	return system("pause");
#else
	return 0;
#endif
}
#endif