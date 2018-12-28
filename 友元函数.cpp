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
//��Ԫ�����ɷ������˽�г�Ա����������ĳ�Ա���� 
//��Ԫ����������const���� 
//��Ԫ�����������ඨ����κεط�����������������޶������� 
//һ�����������Ƕ�������Ԫ���� ��Ԫ�����ĵ�������ͨ�����ĵ��ú�ԭ����ͬ


