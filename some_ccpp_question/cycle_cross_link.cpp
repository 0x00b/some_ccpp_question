/*****************************************************
** �����л��������棬�����л���һЩ�жϣ��������
**
**
********************************************************/

#include "main.h"

#if _CYCLE_CROSS_LINK_

/*
* �ڵ㶨��
*/
typedef struct Link
{
	int data;
	struct Link* next;
}PLink;

/*
* ����һ�����������������һ��������
*/
PLink* CreateLink(int* arr, int n)
{
	PLink* phead = NULL;
	PLink* pTemp = NULL;
	PLink* pNode = NULL;

	for (int i = 0; i < n; i++)
	{
		pTemp = (PLink*)malloc(sizeof(PLink));
		pTemp->data = arr[i];
		pTemp->next = NULL;
		if (i == 0)
		{
			pNode = phead = pTemp;
		}
		else
		{
			pNode->next = pTemp;
			pNode = pTemp;
		}
	}
	return phead;
}
/*
* ��ת������תһ�������ĵ�����
*/
PLink* Rervse(PLink** head)
{
	assert(head);
	PLink* thead = *head;
	PLink* pNode = *head;

	while ((*head)->next)
	{
		pNode = (*head)->next;
		(*head)->next = pNode->next;
		pNode->next = thead;
		thead = pNode;
	}
	*head = thead;
	return thead;
}
/*
* �ж������ǲ����л�
* ������ָ��׷�ϵķ�ʽ��һ��ָ��һ����������һ��ָ��һ����һ��������л�������ָ��ض�����
* ���ص�һ�������Ľڵ�
*/
PLink* LinkCyc(PLink* h)
{
	assert(h);
	PLink* p1 = h;
	PLink* p2 = h;
	while (p1 && p1->next) //�л��˳������߿��ָ������ܵ�����β����ѭ��
	{
		p1 = p1->next->next; //fast pointer
		p2 = p2->next;		 //slower pointer

		if (p1 == p2) //����������л�
		{
			return p1;
		}
	}
	return NULL;
}

/*
* ʹ�����ڵ�n���ڵ㿪ʼѭ��
* ����
* 1->2->3->4->5->6->7->8->NULL
* �ڵ��ĸ��ڵ㿪ʼѭ��������
* 1->2->3->4->5->6->7->8��
*         ��             ��
*          ��-------------
*/
void MkLinkCyc(PLink* h, int n)
{
	assert(h);
	PLink* p = h;
	PLink* p1 = h;
	int count = 0;

	while (p->next)
	{
		p = p->next;
		count++;

		if (count < n)
		{
			p1 = p1->next;
		}
	}
	p->next = p1;

}
/*
* ʹ�ڶ�������Ľ�β�����ڵ�һ������ĵ�n���ڵ㡣
* ���� 
* 1->2->3->4->5->6->7->8->NULL
* 11->22->33->44->NULL
* �� n=5ʱ��
* 
*      1->2->3->4->5->6->7->8->NULL
*                 ��
*  11->22->33->44��
*/
int  MkLinkCross(PLink* h1, PLink* h2, int n)
{
	assert(h1 && h2);
	PLink* p1 = h1;
	PLink* p2 = h2;
	while (p2->next)
	{
		p2 = p2->next;
	}
	for (int i = 0; i < n && p1->next; i++)
	{
		p1 = p1->next;
	}
	if (p1)
	{
		p2->next = p1;
		return 0;
	}
	return -1;
}

/*
* �ҵ�ѭ�����λ��
* 
* 1->2->3->4->5->6->7->8��
*         ��             ��
*          ��-------------
* �򷵻�4��λ��
*/
PLink* GetCycNode(PLink* h)
{
	assert(h);
	PLink* p1 = h;
	PLink* p2 = LinkCyc(h);;

	if (NULL == p2)
	{
		return NULL;
	}
	while (p1)
	{
		if (p1 == p2)
		{
			return p1;
		}
		p1 = p1->next;
		p2 = p2->next;
	}
	return NULL;
}
/*
* �ж�һ���л���������һ�������ǲ��ǽ���
* ����ֵ��-1 �޻��� 0 �޽��棬 1 �н���
* ���жϵ�һ�������Ƿ��л�������У���ô���������ཻ����Ȼ�����л���
* ������ͬһ��������ô�ض��ڻ���ĳ������
* 
*    1->2->3->4->5->6
*            ��     ��
*             9<-8<-7<-33<-22<-11
*/
int JadgeCycLinkCross(PLink* h1, PLink* h2)
{
	assert(h1 && h2);
	PLink* p1 = LinkCyc(h1);
	//��һ�������Ƿ��л�
	if (NULL == p1)
	{
		return -1;
	}
	PLink* p2 = h2;
	while (p2)
	{
		if (p1 == p2)
		{
			return 1;
		}
		p2 = p2->next;
	}
	return 0;
}

/*
*�ҵ��л��������������Ľ���㡣��
*���������ڻ��ϣ�������������㲻��ͬһ���ڵ㣬���һ�����ǽ���㡣
*�������жϻ����ǲ���ͬһ���㣬����ǽ���������ǰ�棬������ǣ��򽻲�������������㡣
*���������ͬһ���㣬��ô�ӻ���֮ǰ���ڻ��ϵ�ĳ������ǽ���㡣
*����ֵ�� -1 �޽��棬1 һ������㣬2 ���������
*/
int GetCycLinkCrossNode(PLink* h1, PLink* h2, PLink** outNode1, PLink** outNode2)
{
	assert(h1 && h2);
	PLink* p1 = GetCycNode(h1); //�ҵ�����1��ʼѭ���Ľڵ�
	PLink* p2 = GetCycNode(h2); //�ҵ�����2��ʼѭ���Ľڵ�
	PLink* p3 = NULL;

	//�������һ���л�����һ��û�У���Ȳ����棬
	//������û�л������������û�С�����Ϊ�����Ѿ���������һ�����л�
	if (!(p1 && p2))
	{
		return -1;
	}

	//������㲻һ�����Ǿ����ڻ��Ͻ��档����ͼ��ÿ������Ļ�����ǽ����
	/* 1->2->3->4->5->6
	*          ��     ��
	*           9<-8<-7<-33<-22<-11
	*/
	if (p1 != p2)
	{
		*outNode1 = p1;
		*outNode2 = p2;
		return 2;
	}

	//������ڻ���,�������������
	/* 
	*         1->2->3->4->5->6
	*           ��    ��     ��
	*   11->22->33     9<-8<-7
	*
	*  ������4����ô�������������4�Ľڵ�����len1��len2
	*  Ȼ�󳤵�һ�������ȴ�����ͷ��ʼ��abs(len1-len2)���ڵ㣬��ͬʱһ���ߣ���������ǽ����
	*/
	p2 = h1;
	p3 = h2;
	int len1 = 0, len2 = 0;
	while (p2 != p1)
	{
		len1++;
		p2 = p2->next;
	}
	while (p3 != p1)
	{
		len2++;
		p3 = p3->next;
	}
	p2 = h1;
	p3 = h2;
	if (len1 > len2)
	{
		for (int i = 0; i < len1 - len2; i++)
		{
			p2 = p2->next;
		}
	}
	else
	{
		for (int i = 0; i < len2 - len1; i++)
		{
			p3 = p3->next;
		}
	}
	while (p2 != p3)
	{
		p2 = p2->next;
		p3 = p3->next;
	}
	*outNode1 = p2;
	return 1;
}

/*
*�����������������,�ڶ����ӽ����Ͽ�����Ӱ���һ������
*����ֵ��-1 �޻��� 0 ����ɹ�
*/
int DepartCrossLink(PLink* h1, PLink* h2)
{
	assert(h1 && h2);
	PLink* p1 = NULL;
	PLink* p2 = NULL;
	PLink* p3 = NULL;
	int res = JadgeCycLinkCross(h1, h2);
	if (1 != res)
	{
		return res;
	}
	res = GetCycLinkCrossNode(h1, h2, &p1, &p2);
	if (-1 == res)
	{
		return -1;
	}
	else if (1 == res)//�����һ������㡣�����ڻ��⡣
	{
		p3 = h2;
		while (p3 && p3->next)
		{
			if (p3->next == p1)
			{
				p3->next = NULL;
				return 0;
			}
			p3 = p3->next;
		}
	}
	else //�����ڻ���
	{
		p3 = h2;
		while (p3 && p3->next)
		{
			if (p3->next == p2)
			{
				p3->next = NULL;
				return 0;
			}
			p3 = p3->next;
		}
	}
	return 0;
}

/*
*�⿪�л�����Ļ�����ʹ֮��Ϊһ�������ĵ�����
*/
void InterruptCycLink(PLink* h)
{
	assert(h);
	PLink* p = GetCycNode(h);
	PLink* p1 = h;
	if (NULL == p)
	{
		return;
	}
	int count = 0;
	while (p1 && p1->next)
	{
		if (p1->next == p)
		{
			count++;
			if (count>1)
			{
				p1->next = NULL;
				return;
			}
		}
		p1 = p1->next;
	}
}
/*
*������������������Ҫ���ˡ���
*/
void FreeLink(PLink* h)
{
	assert(h);
	PLink* p1 = h;
	PLink* p2 = NULL;
	while (p1)
	{
		p2 = p1;
		p2->next = NULL;
		p1 = p1->next;
		free(p2);
		p2 = NULL;
	}

}


/*
*���ѭ�����������
*���ҵ�ѭ���ĵ㣬Ȼ��������ڶ������������ľͽ�������
*/
void DispCycLink(PLink* h)
{
	assert(h);
	PLink* p = GetCycNode(h);
	PLink* p1 = h;
	int count = 0;
	if (NULL == p)//û�л����򵥱���
	{
		while (p1)
		{
			printf("(%d)%d->", p1, p1->data);
			p1 = p1->next;
		}
		printf("END\n");
		return;
	}
	while (p1)
	{
		if (p1 == p)
		{
			count++;
			if (count > 1)
			{
				printf("END\n");
				break;
			}
			printf("(����)");
		}
		printf("(%d)%d->", p1, p1->data);
		p1 = p1->next;
	}
}
int main()
{
	int a[] = { 1,2,3,4,5,6,7,78,99 };
	int a1[] = { 22,33,44 };
	PLink* h = CreateLink(a, 9);
	PLink* h1 = CreateLink(a1, 3);

	printf("��ʼ:\n");
	printf("link1:");
	DispCycLink(h);
	printf("link2:");
	DispCycLink(h1);

	PLink* p = LinkCyc(h);
	printf("\nlink1:MkLinkCyc֮ǰ���Ƿ��л���0��û�У���������һ�������ڵ� ���� %d\n", p);
	MkLinkCyc(h, 6);

	p = LinkCyc(h);
	printf("link1:MkLinkCyc֮���Ƿ��л���0��û�У���������һ�������ڵ� ���� %d\n", p);

	//ʹ�����������ڵ�һ������ĵ�N���ڵ�
	MkLinkCross(h, h1, 4);

	p = LinkCyc(h1);
	printf("\nlink2:MkLinkCross֮���Ƿ��л���0��û�У����������ڵ� ���� %d\n\n", p);

	printf("���棬�л�:\n");
	printf("�����л�link1:");
	DispCycLink(h);
	printf("�����л�link2:");
	DispCycLink(h1);

	int res = JadgeCycLinkCross(h, h1);
	printf("\n���������ǲ��ǽ���(1���У�0��û��):%d\n", res);
	PLink* p1 = NULL;
	res = GetCycLinkCrossNode(h, h1, &p, &p1);
	printf("������=%d�������1=%d�������2=%d\n", res, p, p1);

	DepartCrossLink(h, h1);

	printf("���������:\n");
	printf("link2:");
	DispCycLink(h1);

	InterruptCycLink(h);
	printf("\n�⿪����:\n");
	p = LinkCyc(h);
	printf("link1:�Ƿ��л���0��û�У��������� ���� %d\n\n", p);
	printf("link1:");
	DispCycLink(h);

	//����ͷ���������
	FreeLink(h);
	FreeLink(h1);

#ifdef _WIN32
	return system("pause");
#else
	return 0;
#endif
}

#endif //