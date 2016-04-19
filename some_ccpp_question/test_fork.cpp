#include "main.h"

#if !defined(_WIN)
#include <unistd.h>
int main()
{
	int pid;
	int num = 1;
	for (int i = 0; i < 3; i++)
	{
		printf(" %d ",num);
		num++;
		fork();
	}
	return 0;
}

#endif
