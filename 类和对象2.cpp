#include<iostream>
#include<malloc.h>
#include<assert.h>
#include<string.h>
using namespace std;
#pragma warning(disable:4996)
//���6��Ĭ�ϳ�Ա����
//��ʼ�����������캯������������
//�������ƣ��������죬��ֵ���أ�
//ȡ��ַ���أ�const����ȡ��ַ��

/*
class date
{
public:
//�޲ι��캯��
date()
{}
//���ι��캯��
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
//����ͨ������
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


//��������
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
//�������캯��
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


