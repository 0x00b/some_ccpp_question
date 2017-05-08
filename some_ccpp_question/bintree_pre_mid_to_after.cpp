
#include "main.h"

#if _PREMIDTOAFTER_

/*shu
* root : ��ʾ��ǰ���ڵ�
* mid  : ��������
* return: ���ڵ��������е�λ��
* �ҵ����ڵ������������е�λ�ã����������зֳ��������֣�ǰ��һ������������������һ������������
*/
int departmid(char root, char* mid)
{
	int i = 0;
	while (mid[i] != 0)
	{
		if (root == mid[i])
		{	/* ���ڵ��������е�λ�� */
			return i;
		}
		i++;
	}
	/* û�ҵ� ���� -1 */
	return -1;
}

/*
* pre	��ǰ������
* mid	����������
* aft	��������ź�������
* n		: �������г���
*/
void premidtoafter(char* pre, char* mid, char* aft,int& n)
{
	/* ���磺 pre:ABDECFG mid:DBEACGF �� m = 3 , ������DBEΪ������������CGFΪ������������*/
	/* �ҵ����ڵ��������е�λ�� */
	int m = departmid(pre[0], mid);
	if (m == -1)
	{  /*û�ҵ�������*/
		return;
	}
	aft[n++] = pre[0];/* ���ڵ���ں������е�һ������������ɵ������ĺ����������,����ջ ������һ�� aft[0] = 'A' */
	
	/* ��δ��������������и��ڵ�֮ǰ�Ĳ��ָ��Ƶ�str�У�Ϊ��������������� */
	char str[100];
	ZeroMemory(str,100);
	strncpy(str, mid , m);/* ������һ�� str = "DBE" */
	str[m + 1] = 0;
	/* �ȵݹ������� */
	premidtoafter(pre + 1 + m, mid + m + 1 , aft, n);
	/* �ٵݹ������� */
	premidtoafter(pre + 1, str, aft, n);
}

int main()
{
	char str1[100] = "ABDECFG";
	char str2[100] = "DBEACGF";
	char aft[100];
	ZeroMemory(aft,100);
	int n = 0;
	premidtoafter(str1, str2, aft,n);
	printf("ǰ��%s\n", str1);
	printf("����%s\n", str2);
	printf("����");
	for (int i = n-1; i >= 0; i--)
	{
		printf("%c",aft[i]);
	}

	printf("\n");

#if defined(_WIN)
	return system("pause");
#else
	return 0;
#endif
}
#endif