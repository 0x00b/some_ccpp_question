#include "main.h"

#if _TEST_STRTOK_
int main()
{
	char ss[] = ";701;702;703;;";
	char* result = NULL;
	char* str = NULL;
	char delms[] = ";";

#if defined(_WIN32) || defined(_WIN64) 
	str = strtok_s(ss, delms, &result); 
#else
	str = strtok(ss,delms);
#endif
	while (NULL != str && 0 != str[0])
 	{
		printf("[%s] [%s]\n", result, str);
#if defined(_WIN32) || defined(_WIN64) 
		str = strtok_s(NULL, delms, &result);
#else
		str = strtok(NULL,delms);
#endif
	}

#ifdef _WIN32
	return system("pause");
#else
	return 0;
#endif
}

#endif //_TEST_STRTOK_
