/*********************************************************************
** 回文数，平方回文数
**
*********************************************************************/

#include "main.h"
#include <math.h>
#if _PALINDROME_

/* from 100 to 1000 */
void square_palindrome()
{
	int res = 0, max = sqrt(1000);
	for (size_t i = 10; i <= max; i++)
	{
		res = i*i;
		if (res/100 == res%10)
		{
			printf("%d ",res);
		}
	}
}

int main()
{
	square_palindrome();

#if defined(_WIN)
	return system("pause");
#else
	return 0;
#endif
}
#endif
