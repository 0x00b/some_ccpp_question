/*
* 主要就是内存对齐的知识
*
*/
#include "main.h"

#if _TEST_SIZEOF_
class C
{
public:
	char a;
	static char b;
	void* p;
	static int* c;
	virtual void f() { printf("f\n"); };
	virtual void f2() { printf("f2\n"); };
private:

};

class A
{
public:
	int i;
	union U
	{
		char buff[13];
		int i;
	}u;
	void foo() {}
	typedef char* (*f)(void*);
	enum {r,b,g}color;
};
typedef void(*func)(void);

int test()
{
	return printf("test\n");
}
int main()
{
	int ret = sizeof(C);
	printf("size class C:%d\n", ret);
	
	ret = sizeof(A);
	printf("size class TEST:%d\n", ret);

	printf(" %d %d  %d\n", sizeof(func), sizeof(int*), sizeof(C));

	printf(" %d\n", sizeof(test()));//test not run

	C* c = new C();

	func f;
#if defined(WIN64) || defined(_WIN64) || defined(__WIN64__) || defined(__x86_64__)

	long long* p1 = (long long*)c;
	long long* p2 = (long long*)*p1;
	f = (func)(*p2);
#else
	f  = (func)*((int*)*(int*)(c));
#endif

	f();

#if defined(_WIN)
	return system("pause");
#else
	return 0;
#endif
}

#endif