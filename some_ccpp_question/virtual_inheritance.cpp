/*********************************************************************
** c++�̳������
** ��VS�У�����Ŀ�������ԡ����������ԡ���C/C++���������С�������ѡ�������ѡ�/d1reportAllClassLayout����
** �ٴα���ʱ�򣬱�������������ж�����Ķ���ģ�͡������������Ϣ���࣬���ǿ���ʹ�á�Ctrl+F����������ҵ�����ģ�͵������
** �ο���https://www.cnblogs.com/fanzhidongyzby/archive/2013/01/14/2859064.html
** note��˵����������32λϵͳ��ǰ���£�64λϵͳ��ָ��Ϊ8���ֽ�
*********************************************************************/

#include "main.h"

#if _VIRTUAL_INHERITANCE_

#include <iostream>

class A
{
private:
	int a;
public:
	virtual void aa() {};
};
/*
1>class A	size(8):
1>	+---
1> 0	| {vfptr}	//�麯����ָ�룬�����thisƫ��0
1> 4	| a			//����a�ĵ�ַ�����thisƫ����4���ֽ�
1>	+---
1>
1>A::$vftable@:		//�麯����
1>	| &A_meta
1>	|  0
1> 0	| &A::aa	//A::aa�������麯�����еĵ�0��Ԫ��
1>
1>A::aa this adjustor: 0
*/

class B :virtual public  A
{
private:
	int b;
public:
	virtual void bb() {};
};
/*
1>class B	size(20):
1>	+---
1> 0	| {vfptr}
1> 4	| {vbptr}	//�����������ָ��    <----------------------------
1> 8	| b															    |
1>	+---															    |
1>	+--- (virtual base A)											    |
1>12	| {vfptr}							<---------------------------|
1>16	| a															    |
1>	+---															    |
1>																	    |
1>B::$vftable@B@:													    |
1>	| &B_meta														    |
1>	|  0															    |
1> 0	| &B::bb													    |
1>																	    |
1>B::$vbtable@:			//������									    |
1> 0	| -4			//��ǰ�������ʼλ��������������λ��ƫ��Ϊ-4, ��Ϊ�������λ���ڵ�ǰ��Ķ����е�λ��ƫ��Ϊ4��
1> 1	| 8 (Bd(B+4)A)	//�̳���A�࣬A�����ʼλ��������������λ��ƫ��Ϊ8,8+4=12������A�����ʼλ��
1>
1>B::$vftable@A@:		//A���麯����
1>	| -12				//��ǰ�������ʼλ��������������λ��ƫ��Ϊ-12����Ϊ�������λ���ڵ�ǰ��Ķ����е�λ��ƫ��Ϊ12��
1> 0	| &A::aa		
1>
1>B::bb this adjustor: 0
1>vbi:	   class  offset o.vbptr  o.vbte fVtorDisp
1>               A      12       4       4 0
*/

class C :virtual public  B
{
private:
	int c;
public:
	virtual void bb() {};
	virtual void cc() {};
};
/*
1>class C	size(32):
1>	+---
1> 0	| {vfptr}
1> 4	| {vbptr}
1> 8	| c
1>	+---
1>	+--- (virtual base A)
1>12	| {vfptr}
1>16	| a
1>	+---
1>	+--- (virtual base B)
1>20	| {vfptr}
1>24	| {vbptr}
1>28	| b
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


class D : virtual public A
{
private:
	int d;
public:
	virtual void dd() {};
};
/*
1>class D	size(20):
1>	+---
1> 0	| {vfptr}
1> 4	| {vbptr}
1> 8	| d
1>	+---
1>	+--- (virtual base A)
1>12	| {vfptr}
1>16	| a
1>	+---
1>
1>D::$vftable@D@:
1>	| &D_meta
1>	|  0
1> 0	| &D::dd
1>
1>D::$vbtable@:
1> 0	| -4
1> 1	| 8 (Dd(D+4)A)
1>
1>D::$vftable@A@:
1>	| -12
1> 0	| &A::aa
1>
1>D::dd this adjustor: 0
1>vbi:	   class  offset o.vbptr  o.vbte fVtorDisp
1>               A      12       4       4 0
*/

class E : public B, public D
{
private:
	int e;
public:
	virtual void ee() {};
	virtual void aa() {};
};
/*
1>class E	size(36):
1>	+---
1> 0	| +--- (base class B)
1> 0	| | {vfptr}
1> 4	| | {vbptr}
1> 8	| | b
1>	| +---
1>12	| +--- (base class D)
1>12	| | {vfptr}
1>16	| | {vbptr}
1>20	| | d
1>	| +---
1>24	| e
1>	+---
1>	+--- (virtual base A)
1>28	| {vfptr}
1>32	| a
1>	+---
1>
1>E::$vftable@B@:
1>	| &E_meta
1>	|  0
1> 0	| &B::bb
1> 1	| &E::ee
1>
1>E::$vftable@D@:
1>	| -12
1> 0	| &D::dd
1>
1>E::$vbtable@B@:
1> 0	| -4
1> 1	| 24 (Ed(B+4)A)
1>
1>E::$vbtable@D@:
1> 0	| -4
1> 1	| 12 (Ed(D+4)A)
1>
1>E::$vftable@A@:
1>	| -28
1> 0	| &E::aa
1>
1>E::ee this adjustor: 0
1>E::aa this adjustor: 28
1>vbi:	   class  offset o.vbptr  o.vbte fVtorDisp
1>               A      28       4       4 0
*/

class F :public A
{
public:
	virtual void ff() {};
private:
	int f;
};
/*
1>class F	size(12):
1>	+---
1> 0	| +--- (base class A)
1> 0	| | {vfptr}
1> 4	| | a
1>	| +---
1> 8	| f
1>	+---
1>
1>F::$vftable@:
1>	| &F_meta
1>	|  0
1> 0	| &A::aa
1> 1	| &F::ff
1>
1>F::ff this adjustor: 0
*/

class G :public A
{
public:
	int g;
private:
	virtual void gg() {};
};
/*
1>class G	size(12):
1>	+---
1> 0	| +--- (base class A)
1> 0	| | {vfptr}
1> 4	| | a
1>	| +---
1> 8	| g
1>	+---
1>
1>G::$vftable@:
1>	| &G_meta
1>	|  0
1> 0	| &A::aa
1> 1	| &G::gg
1>
1>G::gg this adjustor: 0
*/
class H :public F, public G
{
public:
	virtual void hh() {};
	virtual void aa() {};
private:
	int h;
};
/*
1>class H	size(28):
1>	+---
1> 0	| +--- (base class F)
1> 0	| | +--- (base class A)
1> 0	| | | {vfptr}
1> 4	| | | a
1>	| | +---
1> 8	| | f
1>	| +---
1>12	| +--- (base class G)
1>12	| | +--- (base class A)
1>12	| | | {vfptr}
1>16	| | | a
1>	| | +---
1>20	| | g
1>	| +---
1>24	| h
1>	+---
1>
1>H::$vftable@F@:
1>	| &H_meta
1>	|  0
1> 0	| &H::aa
1> 1	| &F::ff
1> 2	| &H::hh
1>
1>H::$vftable@G@:
1>	| -12
1> 0	| &thunk: this-=12; goto H::aa
1> 1	| &G::gg
1>
1>H::hh this adjustor: 0
1>H::aa this adjustor: 0
*/



int main()
{
	std::cout << sizeof(A) << std::endl;
	std::cout << sizeof(B) << std::endl;
	std::cout << sizeof(C) << std::endl;
	std::cout << sizeof(D) << std::endl;
	std::cout << sizeof(E) << std::endl;
	std::cout << sizeof(F) << std::endl;

#if defined(_WIN)
	return system("pause");
#else
	return 0;
#endif
}

#endif //_TEST_STRTOK_
