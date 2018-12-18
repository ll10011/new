#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;

class Date 
{
	public:    
		Date(int year = 1900, int month = 1, int day = 1)
		{
			_year = year;
			_month = month;
			_day = day;
		}

		void print()
		{
			cout << _year << "-" << _month << "-" << _day << endl;
		}

		int  IsInvalid()
		{
			if (_year >= 1900&&_month > 0&&_month<13&&_day>0&&_day <= getday(_year, _month))
			{
				return 1;
			}
			else
				return 0;
		}

		int getday(int _year,int _month)
		{
			int arr1[7] = { 1, 3, 5, 7, 8, 10, 12 };
			int arr2[4] = { 4, 6, 9, 11 };
			for (int i = 0; i < 7; i++)
			{
				if (_month == arr1[i])
				{
					return 31;
				}
			}

			for (int j = 0; j < 4; j++)
			{
				if (_month == arr2[j])
				{
					return 30;
				}
			}

			if ((_year % 100 != 0) && (_year % 4 == 0) || (_year % 400 == 0))
			{
				if (_month == 2)
				{
					return 28;
				}
				else
					return 29;
			}
		}

		Date(const Date& d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}

		Date& operator=(const Date& d)
		{
			if (this != &d)
			{
				_year = d._year;
				_month = d._month;
				_day = d._day;
			}
		}

		Date operator+(int days)
		{
			if (days < 0)
			{
				return *this - days;
			}
			Date tmp(*this);
			tmp._day += days;
			while (tmp.IsInvalid() == 0)
			{
				tmp._day -= getday(tmp._year, tmp._month);
				if (tmp.IsInvalid() == 12)
				{
					tmp._year++;
					tmp._month = 1;
				}
				else
				{
					tmp._month++;
				}
			}
			return tmp;
		}

		Date operator-(int days)
		{
			if (days < 0)
			{
				return *this + (-days);
			}
			Date tmp(*this);
			tmp._day -= days;
			while (tmp.IsInvalid() == 0)
			{
				if (tmp.IsInvalid() == 1)
				{
					tmp._year--;
					tmp._month = 12;
				}
				else
				{
					tmp._month--;
				}
				int day = getday(tmp._year, tmp._month);
				tmp._day += _day;
			}
			return tmp;
		}

		int operator-(const Date& d)//判断两个日期相差多少天
		{
			int sum1 = 0;
			int sum2 = 0;
			int sum3 = 0;
			int sum = 0;
			for (int i = 1; i < _month; i++)
			{
				sum1 += getday(_year, _month);
			}
			sum1 += _day;
			for (int j = 1; j < d._month; j++)
			{
				sum2 += getday(d._year, d._day);
			}
			sum2 += _day;

			sum3 = abs(sum1 - sum2);
			if (_year == d._year)
			{
				return abs(sum1 - sum2);
			}
			else if (_year<d._year)	
			{
				for (int m = _year; m < d._year; m++)
				{
					if ((d._year % 100 != 0) && (d._year % 4 == 0) || (d._year % 400 == 0))
					{
						sum += 366;
					}
					else
					{
						sum += 355;
					}
				}
				return abs(sum - sum3);
			}
			else if (_year>d._year)
			{
				for (int n = d._year; n < _year; n++)
				{
					if ((_year % 100 != 0) && (_year % 4 == 0) || (_year % 400 == 0))
					{
						sum += 366;
					}
					else
					{
						sum += 355;
					}
				}
				return abs(sum - sum3);
			}
		}

		Date& operator+=(int)
		{
			*this = *this + 1;
			return *this;
		}

		Date& operator-=(int)
		{
			*this = *this - 1;
			return *this;
		}

		Date& operator++()//前置++
		{
			*this +=1;
			return *this;
		}
		Date operator++(int)//后置++
		{
			Date tmp(*this);
			*this += 1;
			return tmp;
		}
		Date& operator--()
		{
			*this -= 1;
			return *this;
		}
		Date operator--(int)
		{
			Date tmp(*this);
			*this -= 1;
			return tmp;
		}
		bool operator>(const Date& d)const
		{
			if (((_year > d._year) || (_year == d._year)) && ((_month > d._month) || (_month == d._month)) && ((_day > d._day) || (_day == d._day)))
			{
				return true;
			}
			return false;
		}
		bool operator>=(const Date& d)const
		{
			return *this>d||*this==d;
		}
		bool operator<(const Date& d)const
		{
			return !(*this>=d);

		}
		bool operator<=(const Date& d)const
		{
			return *this<d||*this==d;

		}
		bool operator==(const Date& d)const
		{
			return *this==d;

		}
		bool operator!=(const Date& d)const
		{
			return !(*this==d);

		}
private:    
	int _year;    
	int _month;    
	int _day;

};

void testdate()
{
	Date d1(2018, 1, 1);
	//d1.print();

	Date d2(2016, 1, 1);
	//d2.print();

	int d3 = d1 - d2;
	cout << "相差天数为：" << d3<<endl;
}
int main()
{
	testdate();
	return 0;
}