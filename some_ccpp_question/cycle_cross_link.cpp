/*****************************************************
** 链表有环，链表交叉，交叉有环的一些判断，解决方法
**
**
********************************************************/

#include "main.h"

#if _CYCLE_CROSS_LINK_

/*
* 节点定义
*/
typedef struct Link
{
	int data;
	struct Link* next;
}PLink;

/*
* 根据一个传入的数组来创建一个单链表
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
* 逆转链表，逆转一个正常的单链表
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
* 判断链表是不是有环
* 用链表指针追赶的方式，一个指针一次走两步，一个指针一次走一步，如果有环，两个指针必定相遇
* 返回第一次相遇的节点
*/
PLink* LinkCyc(PLink* h)
{
	assert(h);
	PLink* p1 = h;
	PLink* p2 = h;
	while (p1 && p1->next) //有环退出，或者快的指针最后跑到链表尾结束循环
	{
		p1 = p1->next->next; //fast pointer
		p2 = p2->next;		 //slower pointer

		if (p1 == p2) //如果相遇则有环
		{
			return p1;
		}
	}
	return NULL;
}

/*
* 使链表在第n个节点开始循环
* 例如
* 1->2->3->4->5->6->7->8->NULL
* 在第四个节点开始循环，则变成
* 1->2->3->4->5->6->7->8→
*         ↑             ↓
*          ←-------------
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
* 使第二条链表的结尾连接在第一条链表的第n个节点。
* 例如 
* 1->2->3->4->5->6->7->8->NULL
* 11->22->33->44->NULL
* 则 n=5时：
* 
*      1->2->3->4->5->6->7->8->NULL
*                 ↑
*  11->22->33->44→
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
* 找到循环点的位置
* 
* 1->2->3->4->5->6->7->8→
*         ↑             ↓
*          ←-------------
* 则返回4的位置
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
* 判断一条有环链表与另一条链表是不是交叉
* 返回值：-1 无环， 0 无交叉， 1 有交叉
* 先判断第一条链表是否有环，如果有，那么两条链表相交，必然都是有环，
* 而且是同一个环，那么必定在环上某点相遇
* 
*    1->2->3->4->5->6
*            ↑     ↓
*             9<-8<-7<-33<-22<-11
*/
int JadgeCycLinkCross(PLink* h1, PLink* h2)
{
	assert(h1 && h2);
	PLink* p1 = LinkCyc(h1);
	//第一条链表是否有环
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
*找到有环交叉的两条链表的交叉点。。
*如果交叉点在环上，则两条链表交叉点不是同一个节点，并且环点就是交叉点。
*所以先判断环点是不是同一个点，如果是交叉点可能在前面，如果不是，则交叉点就是这个两个点。
*如果环点是同一个点，那么从环点之前不在环上的某个点就是交叉点。
*返回值： -1 无交叉，1 一个交叉点，2 两个交叉点
*/
int GetCycLinkCrossNode(PLink* h1, PLink* h2, PLink** outNode1, PLink** outNode2)
{
	assert(h1 && h2);
	PLink* p1 = GetCycNode(h1); //找到链表1开始循环的节点
	PLink* p2 = GetCycNode(h2); //找到链表2开始循环的节点
	PLink* p3 = NULL;

	//如果其中一条有环，另一条没有，则比不交叉，
	//两条都没有环的情况在这里没有。。因为我们已经假设其中一条必有环
	if (!(p1 && p2))
	{
		return -1;
	}

	//如果环点不一样，那就是在环上交叉。如下图，每条链表的环点就是交叉点
	/* 1->2->3->4->5->6
	*          ↑     ↓
	*           9<-8<-7<-33<-22<-11
	*/
	if (p1 != p2)
	{
		*outNode1 = p1;
		*outNode2 = p2;
		return 2;
	}

	//交叉点在环外,如下这种情况，
	/* 
	*         1->2->3->4->5->6
	*           ↑    ↑     ↓
	*   11->22->33     9<-8<-7
	*
	*  环点是4，那么计算出两条链表到4的节点数，len1，len2
	*  然后长的一条链表先从链表头开始走abs(len1-len2)个节点，再同时一起走，相遇点就是交叉点
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
*分离两条交叉的链表,第二条从交叉点断开。不影响第一条链表。
*返回值：-1 无环， 0 分离成功
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
	else if (1 == res)//如果是一个交叉点。交叉在环外。
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
	else //交叉在环上
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
*解开有环链表的环。。使之成为一条正常的单链表
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
*销毁链表。。。。。不要忘了。。
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
*输出循环链表的内容
*先找到循环的点，然后遍历到第二次遇到这个点的就结束。。
*/
void DispCycLink(PLink* h)
{
	assert(h);
	PLink* p = GetCycNode(h);
	PLink* p1 = h;
	int count = 0;
	if (NULL == p)//没有环，简单遍历
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
			printf("(环点)");
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

	printf("初始:\n");
	printf("link1:");
	DispCycLink(h);
	printf("link2:");
	DispCycLink(h1);

	PLink* p = LinkCyc(h);
	printf("\nlink1:MkLinkCyc之前，是否有环（0：没有，其他：第一次相遇节点 ）： %d\n", p);
	MkLinkCyc(h, 6);

	p = LinkCyc(h);
	printf("link1:MkLinkCyc之后，是否有环（0：没有，其他：第一次相遇节点 ）： %d\n", p);

	//使两个链表交叉在第一条链表的第N个节点
	MkLinkCross(h, h1, 4);

	p = LinkCyc(h1);
	printf("\nlink2:MkLinkCross之后，是否有环（0：没有，其他：环节点 ）： %d\n\n", p);

	printf("交叉，有环:\n");
	printf("交叉有环link1:");
	DispCycLink(h);
	printf("交叉有环link2:");
	DispCycLink(h1);

	int res = JadgeCycLinkCross(h, h1);
	printf("\n两条链表是不是交叉(1：有，0：没有):%d\n", res);
	PLink* p1 = NULL;
	res = GetCycLinkCrossNode(h, h1, &p, &p1);
	printf("交叉数=%d，交叉点1=%d，交叉点2=%d\n", res, p, p1);

	DepartCrossLink(h, h1);

	printf("分离链表后:\n");
	printf("link2:");
	DispCycLink(h1);

	InterruptCycLink(h);
	printf("\n解开链表环:\n");
	p = LinkCyc(h);
	printf("link1:是否有环（0：没有，其他：有 ）： %d\n\n", p);
	printf("link1:");
	DispCycLink(h);

	//最后释放链表。。。
	FreeLink(h);
	FreeLink(h1);

#ifdef _WIN32
	return system("pause");
#else
	return 0;
#endif
}

#endif //