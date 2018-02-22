/*********************************************************************
** c++继承与虚表
** 在VS中，在项目——属性——配置属性——C/C++——命令行——其他选项中添加选项“/d1reportAllClassLayout”。
** 再次编译时候，编译器会输出所有定义类的对象模型。由于输出的信息过多，我们可以使用“Ctrl+F”查找命令，找到对象模型的输出。
*********************************************************************/

#include "main.h"

#if _VIRTUAL_INHERITANCE_

#include <iostream>

class A
{
private:
	int k;
public:
	virtual void aa() {};
};
/*
1>class A	size(8):
1>	+---
1> 0	| {vfptr}	//偏移地址0
1> 4	| k			//偏移地址4
1>	+---
1>
1>A::$vftable@://虚表
1>	| &A_meta
1>	|  0
1> 0	| &A::aa
1>
1>A::aa this adjustor: 0
1>
*/

class B :public virtual A
{
private:
	int j;
public:
	virtual void bb() {};
};
/*

1>class B	size(20):
1>	+---
1> 0	| {vfptr}
1> 4	| {vbptr}
1> 8	| j
1>	+---
1>	+--- (virtual base A)
1>12	| {vfptr}
1>16	| k
1>	+---
1>
1>B::$vftable@B@:
1>	| &B_meta
1>	|  0
1> 0	| &B::bb
1>
1>B::$vbtable@:
1> 0	| -4
1> 1	| 8 (Bd(B+4)A)
1>
1>B::$vftable@A@:
1>	| -12
1> 0	| &A::aa
1>
1>B::bb this adjustor: 0
1>vbi:	   class  offset o.vbptr  o.vbte fVtorDisp
1>               A      12       4       4 0
1>
*/

class C :public virtual B
{
private:
	int i;
public:
	virtual void bb() {};
	virtual void cc() {};
};
/*
1>class C	size(32):
1>	+---
1> 0	| {vfptr}
1> 4	| {vbptr}
1> 8	| i
1>	+---
1>	+--- (virtual base A)
1>12	| {vfptr}
1>16	| k
1>	+---
1>	+--- (virtual base B)
1>20	| {vfptr}
1>24	| {vbptr}
1>28	| j
1>	+---
1>
1>C::$vftable@:
1>	| &C_meta
1>	|  0
1> 0	| &C::cc
1>
1>C::$vbtable@C@:
1> 0	| -4
1> 1	| 8 (Cd(C+4)A)
1> 2	| 16 (Cd(C+4)B)
1>
1>C::$vftable@A@:
1>	| -12
1> 0	| &A::aa
1>
1>C::$vftable@B@:
1>	| -20
1> 0	| &C::bb
1>
1>C::$vbtable@B@:
1> 0	| -4
1> 1	| -12 (Cd(B+4)A)
1>
1>C::bb this adjustor: 20
1>C::cc this adjustor: 0
1>vbi:	   class  offset o.vbptr  o.vbte fVtorDisp
1>               A      12       4       4 0
1>               B      20       4       8 0
*/

class CC :public B, public C
{
public:
	virtual void ccc() {};
};
/*
1>class CC	size(44):
1>	+---
1> 0	| +--- (base class B)
1> 0	| | {vfptr}
1> 4	| | {vbptr}
1> 8	| | j
1>	| +---
1>12	| +--- (base class C)
1>12	| | {vfptr}
1>16	| | {vbptr}
1>20	| | i
1>	| +---
1>	+---
1>	+--- (virtual base A)
1>24	| {vfptr}
1>28	| k
1>	+---
1>	+--- (virtual base B)
1>32	| {vfptr}
1>36	| {vbptr}
1>40	| j
1>	+---
1>
1>CC::$vftable@B@:
1>	| &CC_meta
1>	|  0
1> 0	| &B::bb
1> 1	| &CC::ccc
1>
1>CC::$vftable@:
1>	| -12
1> 0	| &C::cc
1>
1>CC::$vbtable@:
1> 0	| -4
1> 1	| 20 (CCd(B+4)A)
1> 2	| 28 (CCd(CC+4)B)
1>
1>CC::$vbtable@C@:
1> 0	| -4
1> 1	| 8 (CCd(C+4)A)
1> 2	| 16 (CCd(C+4)B)
1>
1>CC::$vftable@A@:
1>	| -24
1> 0	| &A::aa
1>
1>CC::$vftable@B@C@:
1>	| -32
1> 0	| &C::bb
1>
1>CC::$vbtable@B@:
1> 0	| -4
1> 1	| -12 (CCd(B+4)A)
1>
1>CC::ccc this adjustor: 0
1>vbi:	   class  offset o.vbptr  o.vbte fVtorDisp
1>               A      24       4       4 0
1>               B      32       4       8 0
*/

class D : public A
{
private:
	int k;
public:
	virtual void dd() {};
};
/*
1>class D	size(12):
1>	+---
1> 0	| +--- (base class A)
1> 0	| | {vfptr}
1> 4	| | k
1>	| +---
1> 8	| k
1>	+---
1>
1>D::$vftable@:
1>	| &D_meta
1>	|  0
1> 0	| &A::aa
1> 1	| &D::dd
1>
1>D::dd this adjustor: 0
1>
*/

class E : public D
{
private:
	int m;
public:

	virtual void ee() {};

};
/*
1>class E	size(16):
1>	+---
1> 0	| +--- (base class D)
1> 0	| | +--- (base class A)
1> 0	| | | {vfptr}
1> 4	| | | k
1>	| | +---
1> 8	| | k
1>	| +---
1>12	| m
1>	+---
1>
1>E::$vftable@:
1>	| &E_meta
1>	|  0
1> 0	| &A::aa
1> 1	| &D::dd
1> 2	| &E::ee
1>
1>E::ee this adjustor: 0
*/
int main()
{
	std::cout << sizeof(A) << std::endl;
	std::cout << sizeof(B) << std::endl;
	std::cout << sizeof(C) << std::endl;
	std::cout << sizeof(D) << std::endl;
	std::cout << sizeof(E) << std::endl;

#if defined(_WIN)
	return system("pause");
#else
	return 0;
#endif
}

#endif //_TEST_STRTOK_
