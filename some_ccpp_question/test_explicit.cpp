#include <iostream>
#include <conio.h>
#include "main.h"

#if _TEST_EXPLICIT_
using namespace std;

void f1()
{
	throw exception();
}

void f2()
{
	f1();
}
class  T
{
public:
	explicit T(int n)
	{
		m = n;
	}


	int m;
private:
};
int main()
{
	T t = 1.3f;//隐式调用不可取，不能通过编译

	printf("%d", t.m);
	_getch();
	try
	{
		f2();
	}
	catch (const std::exception&)
	{
		cout << "sss";
	}
	catch (...)
	{
		cout << "vv";
	}
	return 0;
}

#endif //_TEST_EXPLICIT_