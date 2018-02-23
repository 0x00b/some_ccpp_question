/*
* 主要就是new的知识
*
*/
#include "main.h"

#if _TEST_NEW_

#include <iostream>

class Test
{
public: 
	Test(int n):x(n)
	{
		std::cout << "call Test x:" << x << std::endl;
	}
	~Test()
	{
		std::cout << "call ~Test " << std::endl;
	}
	void func()
	{
		std::cout << "call func x:" << x << std::endl;
	}

private:
	int x;
};

class TestNew
{
public:
#if 1
	void* operator new(size_t sz)
	{
		std::cout << "test new" << std::endl;
#if 0
		return ::operator new(sz);
#else
		void* t = malloc(sz);
		if (NULL == t)
		{
			if (NULL == std::get_new_handler())
			{
				std::cout << "no new_handler" << std::endl;
				throw std::bad_alloc();
			}
			else
			{
				try
				{
					std::cout << "call new_handler" << std::endl;
					std::get_new_handler()();
				}
				catch (const std::bad_alloc& e)
				{
					std::cout << "call new_handler catch bad_alloc" << std::endl;
					throw e;
				}
				catch (const std::exception& e)
				{
					std::cout << "call new_handler catch exception" <<e.what()<< std::endl;
				}
			}
		}
		return t;
#endif
	}
#endif
private:
	double d[1024 * 1024 * 128];
};

void my_newhandler()
{
	std::cout << "my my_newhandler" << std::endl;
	//maybe can do something to free some memory than can success to call operator new after
	throw std::bad_alloc();
}

#if 0
//重载全局的new
void* ::operator new(size_t sz)
{
	std::cout << ":: new" << std::endl;
	return NULL;
}
#endif

int main()
{
	std::set_new_handler(my_newhandler);

	int* p = new int[sizeof(Test)];
	Test* t = new(p) Test(128);//placement new，对p指向的内存用Test的构造函数进行构造
	t->func();
	t->~Test();		//placement new 必须主动调用析构，并且是唯一主动调用析构的情形

	try
	{
		for (size_t i = 0; i < 1024; i++)
		{
			TestNew* t = new TestNew();
			if (NULL == t)
			{
				std::cout << "NULL t" << std::endl;
			}
			//delete t;
		}

	}
	catch (const std::exception& e)
	{
		std::cout << "catch exception:" <<e.what()<< std::endl;
	}
#if defined(_WIN)
	return system("pause");
#else
	return 0;
#endif
}

#endif