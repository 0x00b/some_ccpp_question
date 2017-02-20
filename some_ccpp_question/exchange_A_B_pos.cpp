/*********************************************************************
** £¨a1,a2,a3...an,b1,b2,..bm£© to £¨b1,b2,..bm,a1,a2,a3...an£©
**
*********************************************************************/

#include "main.h"

#if _EXCHANGE_A_B_POS_
/*
* 
*/
void Reverse(int A[], int l , int r, int n)
{
	if (l >= r || r >= n) 
	{
		return ;
	}
	int mid = l + ((r - l) >> 1);
	for (int i = 0; i <= mid -l; i++)
	{
		int temp = A[l + i];
		A[l + i] = A[r - i];
		A[r - i] = temp;
	}
}

void Exchange(int A[], int m, int n, int size)
{
	Reverse(A, 0, m + n - 1, size);
	Reverse(A, 0, n - 1, size);
	Reverse(A, n, m + n - 1, size);
}

int main()
{
	int arr[] = { 1,2,3,4,5, 7,8,9 };

	Exchange(arr, 5, 3 , 8);

	for (int i = 0; i < 8; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

#if defined(_WIN)
	return system("pause");
#else
	return 0;
#endif
}

#endif //_EXCHANGE_A_B_POS_