#include "main.h"

#if _TEST_STRTOK_
int main()
{
	char ss[] = ";701;702;703;;";
	char* result = NULL;
	char* str = NULL;
	char delms[] = ";";

#if defined(_WIN)
	str = strtok_s(ss, delms, &result); 
#else
	str = strtok(ss,delms);
#endif
	while (NULL != str && 0 != str[0])
 	{
		printf("[%s] [%s]\n", result, str);
#if defined(_WIN)
		str = strtok_s(NULL, delms, &result);
#else
		str = strtok(NULL,delms);
#endif
	}
#if !defined(_WIN)
	/* linux/unix ,strsep is better selection*/
	char nstr[]="1sx|ff2|3|334|5";
	char* pstr;
	char* tstr = nstr;
	while((pstr = strsep(&tstr, "|")) != NULL)
	{
		printf("%s\n", pstr);		
	}

#endif

#if defined(_WIN)
	return system("pause");
#else
	return 0;
#endif
}

#endif //_TEST_STRTOK_
