#include<iostream>
#include<string>
#include<assert.h>
#include<vector>
using namespace std;


//Ä£ÄâÊµÏÖ
namespace cup
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T*constiterator;

		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}

		constiterator cbegin()const
		{
			return _start;
		}
		constiterator cend()const
		{
			return _finish;
		}

		size_t ssize()const
		{
			return _finish - _start;	
		}
		size_t capacity()const
		{
			return _endofstorage - _start;
		}

		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{}

		vector(int n, const T&value = T())
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			reserve(n);
			while (n--)
			{
				pushback(value);
			}
		}

		template<class inputiterator>
		vector(inputiterator first, inputiterator last)
		{
			reserve(last - first);
			while (first != last)
			{
				pushback(*first);
				++first;
			}
		}

		vector(const vector<T>& v)
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			reserve(v.capacity());

			iterator it = begin();
			constiterator vit = v.cbegin();
			while (vit != v.cend())
			{
				*it++ = *vit++;
			}

			_finish = _start + v.ssize();
			_endofstorage = _start + v.capacity();
		}

		vector<T>& operator = (vector<T> v)
		{
			Swap(v);
			return *this;
		}

		~vector()
		{
			delete[] _start;
			_start = _finish = _endofstorage = nullptr;
		}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t size = ssize();
				T*tmp = new T[n];
				if (_start)
				{
					for (size_t i = 0; i < size; ++i)
						tmp[i] = _start[i];
				}

				_start = tmp;
				_finish = _start + size;
				_endofstorage = _start + n;
			}
		}

		void resize(size_t n, const T& value = T())
		{
			if (n <= ssize())
			{
				_finish = _start + n;
				return;
			}
			if (n > capacity())
			{
				reserve(n);
			}

			iterator it = _finish;
			iterator _finish = _start + n;
			while (it != _finish)
			{
				*it = value;
				++it;
			}
		}

		void Swap(vector<T>& v)
		{
			swap(_start, v._start);
			swap(_finish, v._finish);
			swap(_endofstorage, v._endofstorage);
		}

		void pushback(const T& x)        
		{ 
			insert(end(), x); 
		}

		void popback()        
		{ 
			erase(--end()); 
		}

		iterator insert(iterator pos, const T& x)
		{
			assert(pos <= _finish);
			if (_finish == _endofstorage)
			{
				size_t size = ssize();
				size_t newcapacity = capacity() == 0 ? 1 : capacity() * 2;

				reserve(newcapacity);
				pos = _start + size;
			}

			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = x;
			++_finish;
			return pos;
		}

		iterator erase(iterator pos)
		{
			iterator begin = pos + 1;
			while (begin != _finish)
			{
				*(begin - 1) = *begin;
				++begin;
			}
			--_finish;

			return pos;
		}

		T& operator[](size_t pos)
		{
			return _start[pos];
		}
		private:
			iterator _start;
			iterator _finish;
			iterator _endofstorage;
	};
}

void test()
{
	cup::vector<int>first;
	cup::vector<int>second(4, 100);

	cup::vector<int> third(second.begin(), second.end());
	cup::vector<int> fourth(third);

	int myints[] = { 16, 2, 77, 29 };
	cup::vector<int> fifth(myints, myints + sizeof(myints) / sizeof(int));

	std::cout << "The contents of fifth are:";   
	for (cup::vector<int>::iterator it = fifth.begin(); 
		it != fifth.end(); ++it)       
		std::cout << ' ' << *it;    
	std::cout << '\n';

	cup::vector<string> strV;    
	strV.pushback("1111");    
	strV.pushback("2222");    
	strV.pushback("3333");    
	strV.pushback("4444");    
	for (size_t i = 0; i < strV.ssize(); ++i)    
	{ 
		cout << strV[i] << " "; 
	}    
	cout << endl;
}

void printvector(const cup::vector<int>& v)
{
	cup::vector<int>::constiterator it = v.cbegin();
	while (it != v.cend())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}
int main()
{
	/*
	std::vector<int> first;                                
	// empty vector of ints  
	std::vector<int> second (4,100);      
	// four ints with value 100  
	std::vector<int> third (second.begin(),second.end());  
	// iterating through second  std::vector<int> fourth (third);                       // a copy of third

	int myints[] = { 16, 2, 77, 29 };  
	std::vector<int> fifth(myints, myints + sizeof(myints) / sizeof(int));
	std::cout << "the contents of fifth are:";  
	for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
		std::cout << ' ' << *it; 
		std::cout << '\n';
    */

	test();

	return 0;
}