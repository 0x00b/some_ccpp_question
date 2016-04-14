/*********************************************************************
** �������飬ʹ�ø�����ǰ�������ں�
** ���ߣ��ַ����к���*�������ַ�,�������飬*��ǰ�������ַ��ں󣬲������˳�򲻱�
**
*********************************************************************/

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

//��ʵ�����㷨�����Ե���������Ǹ�������һ�롣�Ǿ�Ӧ���������������������Ա�֤�����ռ�С��n/2
//�ڶ����㷨��ʵ��ִ��ʱ�併�ͣ�Ҳ�����еݹ���Ǹ��ط�����Ϊ�Ǹ��ط��������ĸ����йأ���������࣬�򵹹���
//�Ӻ�����ǰ���ţ��ƶ�����, 
int ReSort(int a[], int n)
{
	assert(a);
	int nNeg = 0;	//��¼�������ܸ���
	for (int i = 0; n > 0 && i < n; i++)
	{
		if (a[i] < 0)
		{
			nNeg++;	//ͳ�Ƹ����ĸ���
		}
	}
	if (n == nNeg || nNeg == 0)//ȫ���Ǹ���������û�и������ͷ���
	{
		return nNeg;
	}
	int* pa = new int[nNeg] {0};// (int*)malloc(nNeg * sizeof(int));
	if (pa == NULL)
	{
		return 0;
	}
	int nFind = 0;	//ĿǰΪֹ�ҵ��ĸ����ĸ���
	int nStart = 0;	//ÿ��������Ŀ�ʼλ��
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
	return nFind;		//����һ�������˶��ٸ�����
}

int ReSort_1(int a[], int n)
{
	assert(a);
	int nNeg = 0;	//��¼�������ܸ���
	for (int i = 0; n > 0 && i < n; i++)
	{
		if (a[i] < 0)
		{
			nNeg++;	//ͳ�Ƹ����ĸ���
		}
	}
	if (n == nNeg || nNeg == 0)//ȫ���Ǹ���������û�и������ͷ���
	{
		return nNeg;
	}
	int nFind = 0;	//ĿǰΪֹ�ҵ��ĸ����ĸ���
	int nStart = 0;	//ÿ��������Ŀ�ʼλ��
	int nTrip = 0;	//һ�������ҳ��ĸ�������
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
			//�൱�������ѭ������Ϊֻ��һ�����������ƶ�����������λ�ü���
			for (int j = nPos; j > nTrip; j--) 
			{ 
				swap(a[nFind + j], a[nFind + j - 1]);
			}
			nTrip++;
		}
	}
	return nFind;		//����һ�������˶��ٸ�����
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

	printf("����ǰ: ");
	Print(a, len);
	printf("\n");

	ReSort(a, len);

	ReSort_1(b, len);

	printf("\n��һ�������: ");
	Print(a,len);
	printf("\n�ڶ��������: ");
	Print(b, len);

	char str[] = "ab**c*d*ed2";
	printf("\n\n����ǰ��%s\n", str);
	change(str);
	printf("������%s\n",str);

#ifdef _WIN32
	return system("pause");
#else
	return 0;
#endif
}

#endif // _RESORT_ARRAY