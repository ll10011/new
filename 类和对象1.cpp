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
	s.setstudentinfo("peter", "��", 18);
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


//thisָ��
//1. thisָ������ͣ�������* const
//2. ֻ���ڡ���Ա���������ڲ�ʹ��
//3. thisָ�뱾������ʵ��һ����Ա�������βΣ��Ƕ�����ó�Ա����ʱ���������ַ��Ϊʵ�δ��ݸ�this �βΡ����Զ����в��洢thisָ�롣
//4. thisָ���ǳ�Ա������һ��������ָ���βΣ�һ������ɱ�����ͨ��ecx�Ĵ����Զ����ݣ�����Ҫ�û� ����
 
/*
//������
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

