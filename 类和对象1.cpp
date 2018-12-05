#include<string.h>
#include <iostream>
using namespace std;
/*
struct student
{
	void setstudentinfo(const char*name, const char* gender, int age)
	{
		strcpy_s(_name, name);
		strcpy_s(_gender, gender);
		_age = age;
	}

	void printstudentinfo()
	{
		cout << _name << " " << _gender << " " << _age << endl;
	}

	char _name[20];
	char _gender[3];
	int _age;
};

int main()
{
	student s;
	s.setstudentinfo("peter", "男", 18);
	s.printstudentinfo();
	return 0;
}
*/

/*
class person
{
public:
		void printpersoninfo();
private:
	char* _name[20];
	char* _gender[3];
	int _age;
};

void person::printpersoninfo()
{
	cout << _name << " " << _gender << " " << _age << endl;
}
*/


//this指针
//1. this指针的类型：类类型* const
//2. 只能在“成员函数”的内部使用
//3. this指针本质上其实是一个成员函数的形参，是对象调用成员函数时，将对象地址作为实参传递给this 形参。所以对象中不存储this指针。
//4. this指针是成员函数第一个隐含的指针形参，一般情况由编译器通过ecx寄存器自动传递，不需要用户 传递
 
/*
//日期类
class date
{
public:
	void display()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	void setdate(int year, int month, int day)
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

int main()
{
	date d1, d2;
	d1.setdate(2018,12,19);
	d2.setdate(2018,12,20);
	d1.display();
	d2.display();
	return 0;
}
*/

/*
class A
{
public:
	void printA()
	{
		cout << _a << endl;
	}
	void show()
	{
		cout << "show()" << endl;
	}
private:
	int _a;
};

int main()
{
	A L;
	L.printA();
	L.show();
	return 0;
}
*/

