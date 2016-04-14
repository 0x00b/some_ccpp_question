
#include "main.h"

#if _IS_BIG_ENDIAN_

int isBigEndian()
{
	unsigned short i = 1;
	return *(unsigned char*)(&i) != 0x01;
}

int main()
{
	printf("操作系统是:%s\n", isBigEndian() ? "大端" : "小端");

#ifdef _WIN32
	return system("pause");
#else
	return 0;
#endif
}
#endif