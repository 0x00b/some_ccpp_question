
#include "main.h"

#if _TEST_STRTOK_
int main()
{
	char ss[] = ";701;702;703;;";
	char* result = NULL;
	char* str = NULL;
	char delms[] = ";";
	str = strtok_s(ss, delms, &result);
	while (NULL != str && 0 != str[0])
	{
		printf("[%s] [%s]\n", result, str);
		str = strtok_s(NULL, delms, &result);
	}

#ifdef _WIN32
	return system("pause");
#else
	return 0;
#endif
}

#endif //_TEST_STRTOK_