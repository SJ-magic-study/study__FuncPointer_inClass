/************************************************************
URL
	●C++編（言語解説） 第３４章 メンバ関数ポインタ
	http://ppp-lab.sakura.ne.jp/cpp/language/034.html
	
description
	メンバ関数ポインタは、class objectの、先頭からのaddress offsetを格納するようだ。
	なので、ポインタへの代入は、
		p_func = &CLASS_1::func1;
	と、Generalな感じで格納する。
	
	使用時に、thisを使い、使用objectの先頭からのoffsetによって、関数を呼び出す。
************************************************************/
#pragma once



/************************************************************
************************************************************/

/**************************************************
**************************************************/
class CLASS_1{
private:
	
public:
	void func1()
	{
		printf("func 1\n");
	}
	void func2()
	{
		printf("func 2\n");
	}
	void func3()
	{
		printf("func 3\n");
	}
};

/**************************************************
**************************************************/
class CLASS_2{
private:
	typedef void (CLASS_1::*PFUNC)();
	
	CLASS_1 c1;
	CLASS_1* p_c1;
	
public:
	
	CLASS_2()
	: p_c1(&c1)
	{
	}
	
	void func()
	{
		PFUNC p_func;
		
		/********************
		"::"は優先度最高なのだが、
			p_func = &(CLASS_1::func1);
		とすると、何故か compile Error.
		********************/
		p_func = &CLASS_1::func1;
		(c1.*p_func)();
		(p_c1->*p_func)();
		
		p_func = &CLASS_1::func2;
		(c1.*p_func)();
		(p_c1->*p_func)();
	}
	
};
