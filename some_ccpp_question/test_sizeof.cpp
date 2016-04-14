
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
typedef void(*func)(void);
int main()
{
	int ret = sizeof(C);
	printf("class C的大小：%d\n",ret);


	printf(" %d %d  %d\n", sizeof(func), sizeof(int*), sizeof(C));
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

#ifdef _WIN32
	return system("pause");
#else
	return 0;
#endif
}

#endif