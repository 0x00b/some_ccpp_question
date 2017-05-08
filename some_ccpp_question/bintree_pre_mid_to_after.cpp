
#include "main.h"

#if _PREMIDTOAFTER_

/*shu
* root : 表示当前根节点
* mid  : 中序序列
* return: 根节点在中序中的位置
* 找到根节点在中序序列中的位置，把中序序列分成了两部分，前面一部分是左子树，后面一部分是右子树
*/
int departmid(char root, char* mid)
{
	int i = 0;
	while (mid[i] != 0)
	{
		if (root == mid[i])
		{	/* 根节点在中序中的位置 */
			return i;
		}
		i++;
	}
	/* 没找到 返回 -1 */
	return -1;
}

/*
* pre	：前序序列
* mid	：中序序列
* aft	：用来存放后序序列
* n		: 后序序列长度
*/
void premidtoafter(char* pre, char* mid, char* aft,int& n)
{
	/* 例如： pre:ABDECFG mid:DBEACGF 则 m = 3 , 则中序DBE为左子树的中序，CGF为右子树的中序*/
	/* 找到根节点在中序中的位置 */
	int m = departmid(pre[0], mid);
	if (m == -1)
	{  /*没找到不继续*/
		return;
	}
	aft[n++] = pre[0];/* 根节点放在后序序列第一个，反向输出可得真正的后序遍历序列,类似栈 例：第一遍 aft[0] = 'A' */
	
	/* 这段代码把中序遍历的中根节点之前的部分复制到str中，为左子树的中序遍历 */
	char str[100];
	ZeroMemory(str,100);
	strncpy(str, mid , m);/* 例：第一遍 str = "DBE" */
	str[m + 1] = 0;
	/* 先递归右子树 */
	premidtoafter(pre + 1 + m, mid + m + 1 , aft, n);
	/* 再递归左子树 */
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
	printf("前序：%s\n", str1);
	printf("中序：%s\n", str2);
	printf("后序：");
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