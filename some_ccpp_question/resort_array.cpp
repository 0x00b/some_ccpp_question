/*********************************************************************
** 重排数组，使得负数在前，正数在后，
** 或者，字符串中含有*和其他字符,重排数组，*在前，其他字符在后，并且相对顺序不变
**
*********************************************************************/
#include <new>
#include "main.h"

#if _RESORT_ARRAY_

inline void swap(int& a, int& b)
{
	if (a != b)
	{
		a = a^b;
		b = a^b;
		a = a^b;
	}
}

//其实两个算法都可以调整。如果是负数超过一半。那就应该是先排正数，这样可以保证辅助空间小于n/2
//第二个算法的实际执行时间降低，也就是有递归的那个地方，因为那个地方跟负数的个数有关，如果负数多，则倒过来
//从后面往前面排，移动正数, 
int ReSort(int a[], int n)
{
	assert(a);
	int nNeg = 0;	//记录负数的总个数
	for (int i = 0; n > 0 && i < n; i++)
	{
		if (a[i] < 0)
		{
			nNeg++;	//统计负数的个数
		}
	}
	if (n == nNeg || nNeg == 0)//全部是负数，或者没有负数。就返回
	{
		return nNeg;
	}
	int* pa = new int[nNeg] ;// (int*)malloc(nNeg * sizeof(int));
	if (pa == NULL)
	{
		return 0;
	}
	int nFind = 0;	//目前为止找到的负数的个数
	int nStart = 0;	//每个子区间的开始位置
	int nPos = 0;
	int nTrip = 0;	
	memcpy(pa, a, nNeg* sizeof(int));
	for (int i = 0; i < n  ; i++)
	{
		if ((i - nStart) == nNeg)
		{
			nNeg -= nTrip;
			nStart = i;
			nPos = 0;
			nTrip = 0;
		}
		if (a[i] < 0)
		{
			a[nFind++] = a[i];
			a[i] = pa[i - nStart];
			nTrip++;
		}
		else
		{
			if (nPos == 0 && nTrip == 0 && nNeg != 0)
			{
				swap(pa[nPos++], a[i]);
			}
			else
			{
				pa[nPos++] = a[i];
				a[i] = pa[i - nStart];
			}
		}
	}
	return nFind;		//返回一共调整了多少个负数
}

int ReSort_1(int a[], int n)
{
	assert(a);
	int nNeg = 0;	//记录负数的总个数
	for (int i = 0; n > 0 && i < n; i++)
	{
		if (a[i] < 0)
		{
			nNeg++;	//统计负数的个数
		}
	}
	if (n == nNeg || nNeg == 0)//全部是负数，或者没有负数。就返回
	{
		return nNeg;
	}
	int nFind = 0;	//目前为止找到的负数的个数
	int nStart = 0;	//每个子区间的开始位置
	int nTrip = 0;	//一个区间找出的负数个数
	int nPos = 0;
	for (int i = 0; i < n ; i++)
	{
		if (i - nStart == nNeg)
		{
			nStart = i;
			nNeg -= nTrip;
			nFind += nTrip;
			nTrip = 0;
		}
		nPos = i - nStart;
		swap(a[i], a[nFind + nPos]);
		if (a[nFind + nPos] < 0)
		{
			//ReSort_1(a + nFind + nTrip, nPos - nTrip + 1);	
			//相当于下面的循环。因为只有一个负数。。移动到他到合适位置即可
			for (int j = nPos; j > nTrip; j--) 
			{ 
				swap(a[nFind + j], a[nFind + j - 1]);
			}
			nTrip++;
		}
	}
	return nFind;		//返回一共调整了多少个负数
}

void Print(int a[], int n)
{
	assert(a);
	for (int i = 0; i < n; i++)
	{
		printf("%4d ", a[i]);
	}
}

int change(char *str) {

	int i, j = strlen(str) - 1;

	for (i = j; j >= 0; j--)
	{

		if (str[i] != '*')
		{
			i--;
		}
		else if (str[j] != '*')
		{
			str[i] = str[j];

			str[j] = '*';
			i--;
		}
	}
	return i + 1;
}


int main()
{
	int a[] = { -1,-7,-59,-12,15, 33 ,8,9,-999 };
#define len (sizeof(a)/sizeof(int))
	int b[len] ;
	memcpy(b, a, sizeof(a));

	printf("排序前: ");
	Print(a, len);
	printf("\n");

	ReSort(a, len);

	ReSort_1(b, len);

	printf("\n第一种排序后: ");
	Print(a,len);
	printf("\n第二种排序后: ");
	Print(b, len);

	char str[] = "ab**c*d*ed2";
	printf("\n\n调整前：%s\n", str);
	change(str);
	printf("调整后：%s\n",str);

#if defined(_WIN)
	return system("pause");
#else
	return 0;
#endif
}

#endif // _RESORT_ARRAY
