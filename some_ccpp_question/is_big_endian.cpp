
#include "main.h"

#if _IS_BIG_ENDIAN_

int isBigEndian()
{
	unsigned short i = 1;
	return *(unsigned char*)(&i) != 0x01;
}

int main()
{
	printf("system is :%s\n", isBigEndian() ? "big endian" : "litter endian");

#if defined(_WIN)
	return system("pause");
#else
	return 0;
#endif
}
#endif