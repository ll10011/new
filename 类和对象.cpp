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
//1. ÿ����Ա�����ڳ�ʼ���б���ֻ�ܳ���һ��(��ʼ��ֻ�ܳ�ʼ��һ��)
//2. ���а������³�Ա��������ڳ�ʼ���б�λ�ý��г�ʼ���� ���ó�Ա���� const��Ա���� �����ͳ�Ա
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
	A _aobj;     // û��Ĭ�Ϲ��캯��    
	int& _ref;    // ����    
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

//��������ת��
//���캯���������Թ������ʼ�����󣬶��ڵ��������Ĺ��캯��������������ת��������
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
