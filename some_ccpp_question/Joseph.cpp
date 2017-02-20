#include "main.h"

#if _JOSEPH_

#define OUT 1
void joseph_math(int n, int m)
{
	/* 数学推导。得不到出队序列。 
	* If number = 3
	* f(1) = 0
	* f(2) = 1 = (f(1) + 3) % 2
	* f(3) = 1 = (f(2) + 3) % 3
	* f(4) = 0 = (f(3) + 3) % 4
	* f(5) = 3 = (f(4) + 3) % 5
	* ...
	* f(n) = x = (f(n-1) + 3) % n
	* */
	int last = 0; // f(1) = 0
	for (int i = 2; i <= n; ++i)
	{
		last = (last + m) % i;
	}
	printf("The last one is : %d\n" ,last + 1 );

}

/*
链表
*/
typedef struct Node_ 
{
	int n;
	struct Node_* next;
} Node;


void joseph(int n, int m)
{
	int last = 0;
	int k = 1;
	Node* rear = (Node*)malloc(sizeof(Node));
	rear->n = 1;
	rear->next = rear;
	Node* temp = NULL;

	/* 创建循环链表 */
	for (int i = 2; i <= n ; i++)
	{
		temp = (Node*)malloc(sizeof(Node));
		temp->n = i;
		temp->next = rear->next;
		rear->next = temp;
		rear = temp;
	}
	rear = rear->next;

	printf("出队序列 :");
	while (rear->next != rear)/* 判空，只剩rear的时候，rear就是最后一个出队的*/
	{
		if (k++ == m)/* 数到m的出队 */
		{
			printf("%d ", rear->n);
			temp = rear->next;
			last = rear->n;
			k = 1;
			/* 出队方式为先复制后一个的数据到自己，删除后面一个 */
			rear->n = temp->n;
			rear->next = temp->next;
			free(temp);
		}
		else
		{
			rear = rear->next;
		}
	}
	printf("%d\n", rear->n);
	free(rear);
}

int main()
{
	int n, m;
	printf("Joseph:\ninput total:");
	scanf("%d", &n);
	printf("input out-num:");
	scanf("%d", &m);
#if 1
	joseph_math(n,m);
//#else
	joseph(n,m);
#endif

#if defined(_WIN)
	return system("pause");
#else
	return 0;
#endif
}
#endif // JOSEPH
