#include<iostream>
#include<string>
#include<assert.h>
#include<math.h>
#pragma warning(disable:4996)
using namespace std;

namespace bit
{
	class string
	{
	private:
		friend ostream& operator<<(ostream& _cout, const bit::string& s);
	private:
		char* _str;
		size_t _capacity;
		size_t _size;

	public:
		typedef char* iterator;

	public:
		string(const char* str = "")
		{
			if (nullptr == str)
			{
				assert(false);
				return;
			}

			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		string(const string& s)
			:_str(new char[s._capacity + 1])
			, _size(s._size)
			, _capacity(s._capacity)
		{
			strcpy(_str, s._str);
		}

		string& operator=(const string& s)
		{
			if (this != &s)
			{
				char* pstr = new char[s._capacity + 1];
				strcpy(pstr, s._str); 
				delete[] _str;
				_str = pstr;
				_size = s._size;
				_capacity = s._capacity;
			}
			return*this;
		}

		~string()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
		}

		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		void pushback(char c)
		{
			if (_size == _capacity)
			{
				reserve(_capacity * 2);
			}
			_str[_size++] = c;
			_str[_size] = '\0';
		}

		void append(size_t n, char c)
		{
			for (size_t i = 0; i < n; i++)
				pushback(c);
		}

		string& operator+=(char c)
		{
			pushback(c);
			return*this;
		}


		void clear()
		{
			_size = 0;
			_str[_size] = '\0';
		}

		void Swap(string& s)
		{
			swap(_str, s._str);            
			swap(_size, s._size);            
			swap(_capacity, s._capacity);
		}

		const char*c_str()const
		{
			return _str;
		}

		size_t size()const
		{
			return _size;
		}

		size_t capacity()const
		{
			return _capacity;
		}

		bool empty()const
		{
			return 0 == _size;
		}

		void resize(size_t newsize, char c = char())
		{
			if (newsize > _size)
			{
				if (newsize > _capacity)
				{
					reserve(newsize);
				}
				memset(_str + _size, c, newsize - _size);
			}
			_size = newsize;
			_str[newsize] = '\0';
		}

		void reserve(size_t newcapacity)
		{
			if (newcapacity > _capacity)
			{
				char* str = new char[newcapacity + 1];
				strcpy(str, _str);

				delete[] _str;
				_str = str;
				_capacity = newcapacity;
			}
		}

		char& operator[](size_t index)
		{
			assert(index < _size);
			return _str[index];
		}

		const char& operator[](size_t index)const
		{
			assert(index < _size);
			return _str[index];
		}
	};
}

ostream& bit::operator<<(ostream& _cout, const bit::string& s)
{
	cout << s._str;
	return _cout;
}

void testbitstring1()
{
	bit::string s1;
	bit::string s2("hello bit");
	bit::string s3(s2);

	s1 = s3;
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
}

void testbitstring2()
{
	bit::string s1("hello");
	s1.pushback(' ');
	s1.pushback('b');
	s1.append(1, 'i');
	s1 += 't';
	cout << s1 << endl;
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;

	auto it = s1.begin();
	while (it != s1.end())
	{
		cout << *it++;
	}
	cout << endl;

	bit::string s2("hello world!!!");
	s1.Swap(s2);
	cout << s1 << endl;
	cout << s2 << endl;
}

void testbitstring3()
{
	bit::string s("hello");
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.resize(10, 'a');
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.resize(20);
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.resize(5);
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.resize(50);
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;
}
int main()
{
	testbitstring1();
	testbitstring2();
	testbitstring3();
	return 0;
}