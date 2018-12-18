#include<iostream>

using namespace std;


/*
class date
{
public:
	date(int year, int month, int day)
		:_year(year),
		_month(month),
		_day(day)
	{}

private:
	int _year;
	int _month;
	int _day;
};
*/



/*
//1. 每个成员变量在初始化列表中只能出现一次(初始化只能初始化一次)
//2. 类中包含以下成员，必须放在初始化列表位置进行初始化： 引用成员变量 const成员变量 类类型成员
class A
{
public:
	A(int a)
		:_a(a)
	{}

private:
	int _a;

};

class B
{
public:
	B(int a, int ref) 
		:_aobj(a), 
		_ref(ref), 
		_n(10)    
	{} 
private:    
	A _aobj;     // 没有默认构造函数    
	int& _ref;    // 引用    
	const int _n; // const 
};

int main()
{
	return 0;
}
*/

/*
class time
{
public:
	time(int hour=0)
		:_hour(hour)
	{
		cout << "time()" << endl;
	}

private:
	int _hour;
};

class date
{
public:
	date(int day)
	{}

private:
	int _day;
	time _t;
};

int main()
{
	date d(1);
	return 0;
}
*/

//限制类型转换
//构造函数不仅可以构造与初始化对象，对于单个参数的构造函数，还具有类型转换的作用
class date
{
public:
	date(int year)
		:_year(year)
	{}

	//explicit date(int year)
	//	:_year(year)
	//{}
private:
	int _year;
	int _month;
	int _day;
};

void test()
{
	date d1(2019);
	d1 = 2020;
}

int main()
{
	test();
	return 0;
}






/*
class A
{
public:
	A()
	{
		++_scount;
	}
	A(const A& t)
	{
		++_scount;
	}
	static int GetACount()
	{
		return _scount;
	}
private:
	static int _scount;
};

int A::_scount = 0;

void TestA()
{
	cout << A::GetACount() << endl;
	A a1, a2;
	A a3(a1);
	cout << A::GetACount() << endl;
}

int main()
{
	TestA();
	return 0;
}
*/
