#include<iostream>

using namespace std;

//class date
//{
//public:
//	date(int year, int month, int day)
////		:_year(year)
//		, _month(month)
//		, _day(day)
//	{}
//
//	ostream& operator<<(ostream& _cout)
//	{
//		_cout << _year << "-" << _month << "-" << _day;
//		return _cout;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	date d(2018,12,31);
//	d << cout;
//	return 0;
//}

class date
{
	friend ostream& operator<<(ostream& _cout,const date& d);
	friend istream& operator>>(istream& _cin,date& d);
public:
	date(int year, int month, int day)
		:_year(year)
		, _month(month)
		, _day(day)
	{}
private:
	int _year;
	int _month;
	int _day;
};


ostream& operator<<(ostream& _cout,const date& d)
{
	 _cout << d._year << "-" << d._month << '-' << d._day;

	return _cout;
}

istream& operator>>(istream& _cin,date& d)
{
	_cin >> d._year;
	_cin >> d._month;
	_cin >> d._day;

	return _cin;
}

int main()
{
	date d(0, 0, 0);
	cin >> d;
	cout << d << endl;
	return 0;
}
//友元函数可访问类的私有成员，但不是类的成员函数 
//友元函数不能用const修饰 
//友元函数可以在类定义的任何地方声明，不受类访问限定符限制 
//一个函数可以是多个类的友元函数 友元函数的调用与普通函数的调用和原理相同


