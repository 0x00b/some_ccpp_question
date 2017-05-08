/*********************************************************************
** ´óÊıÔËËã
**
*********************************************************************/

#include "main.h"

#if _HUGENUM_OPERATION_


void add(char* in_num1, char* in_num2, char* out_res,int max_res)
{
	int len1 = strlen(in_num1) - 1;
	int len2 = strlen(in_num2) - 1;
	int k = 0, temp = 0;
	int i = len1, j = len2;
	memset(out_res, 0x00 , max_res * sizeof(char));
	for (; i >= 0 && j >= 0; i--, j--, k++)
	{
		temp = in_num1[i] - '0' + in_num2[j] - '0' + (out_res[k] > 0 ? out_res[k] - '0' : 0);
		if (temp >= 10)
		{
			out_res[k + 1] = temp / 10 + '0';
		}
		out_res[k] = temp % 10 + '0';

	}
	for (; i >= 0; i--)
	{
		out_res[k++] += in_num1[i];
	}
	for (; j >= 0; j--)
	{
		out_res[k++] += in_num2[j];
	}
	i = 0, j = strlen(out_res) - 1;
	char tempch;
	for (; i < j; i++, j--)
	{
		tempch = out_res[i];
		out_res[i] = out_res[j];
		out_res[j] = tempch;
	}
}

void mult(char* in_num1, char* in_num2, char* out_res)
{

}


int main()
{
	char num1[100];
	char num2[100];
	char res[100];
	scanf("%s%s", num1, num2);
	add(num1, num2, res, 100);
	printf("%s", res);
#if defined(_WIN)
	return system("pause");
#else
	return 0;
#endif
}

#endif //_BINARY_SEARCH_