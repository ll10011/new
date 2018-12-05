#include<iostream>
#include<malloc.h>
#include<assert.h>
#include<string.h>
using namespace std;
#pragma warning(disable:4996)
//类的6个默认成员函数
//初始化和清理：构造函数，析构函数
//拷贝复制：拷贝构造，赋值重载；
//取地址重载，const对象取地址；

/*
class date
{
public:
//无参构造函数
date()
{}
//带参构造函数
date(int year, int month, int day)
{
_year = year;
_month = month;
_day = day;
}
private:
int _year;
int _month;
int _day;
};

void testdate()
{
date d1;
date d2(2018, 12, 12);
date d3();
}
*/

/*
class date
{
public:
date()
{
_year = 1900;
_month = 1;
_day = 1;
}
date(int year=1900, int month=1, int day=1)
{
_year = year;
_month = month;
_day = day;
}
private:
int _year;
int _month;
int _day;
};

void test()
{
date d1;
}
//不能通过测试
*/


/*
class time
{
public:
time()
{
cout << "time()" << endl;
_hour = 0;
_minute = 0;
_second = 0;
}
private:
int _hour;
int _minute;
int _second;
};

class date
{
private:
int _year;
int _month;
int _day;
time _t;
};
int main()
{
date d;
return 0;
}
*/


//析构函数
/*
typedef int datatype;
class seqlist
{
public:
seqlist(int capacity = 10)
{
_pdata = (datatype*)malloc(capacity*sizeof(datatype));
assert(_pdata);
_size = 0;
_capacity = capacity;
}
~seqlist()
{
if (_pdata)
{
free(_pdata);
_pdata = NULL;
_capacity = 0;
_size = 0;
}
}
private:
int* _pdata;
size_t _size;
size_t _capacity;
};
*/

/*
class String
{
public:
String(const char* str = "jack")
{
_str = (char*)malloc(strlen(str) + 1);
strcpy(_str, str);
}
~String()
{
cout << "~String()" << endl;
free(_str);
}
private:
char* _str;
};

class Person
{
private:
String _name;
int    _age;
};

int main()
{
Person p;
return 0;
}
*/

/*
//拷贝构造函数
class date
{
public:
	date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	date(const date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	date d1;
	date d2(d1);
	return 0;
}
*/


