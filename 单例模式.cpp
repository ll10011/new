/*
//恶汉模式
#include<iostream>
using namespace std;

class singleton
{
private:
	singleton()
	{};
	//c++98
	//singleton(singleton const&);
	//singleton& operator=(singleton const&);

	//c++11
	singleton(singleton const&) = delete;
	singleton& operator=(singleton const&) = delete;

	static singleton m_instance;

public:
	static singleton* getinstance()
	{
		return &m_instance;
	}
};
singleton singleton::m_instance;

void test()
{
	cout << singleton::getinstance() << endl;
}

int main()
{
	test();
	return 0;
}
*/


//懒汉模式
#include<iostream>
#include<mutex>
#include<thread>
using namespace std;

class singleton
{
private:
	singleton()
	{};

	singleton(singleton const&);
	singleton& operator=(singleton const&);

	static singleton* m_pinstance;
	static mutex m_mtx;

public:
	static singleton*getinstance()
	{
		if (nullptr == m_pinstance)
		{
			m_mtx.lock();
			if (nullptr == m_pinstance)
			{
				m_pinstance = new singleton();
			}
			m_mtx.unlock();
		}
		return m_pinstance;
	}
	class cgarbo
	{
	public:
		~cgarbo()
		{
			if (singleton::m_pinstance)
				delete singleton::m_pinstance;
		}
	};
	static cgarbo garbo;
};

singleton*singleton::m_pinstance = nullptr;
singleton::cgarbo garbo;
mutex singleton::m_mtx;

void func(int n)
{
	cout << singleton::getinstance() << endl;
}

int main()
{
	thread t1(func, 10);
	thread t2(func, 10);
	thread t3(func, 10);
	thread t4(func, 10);

	t1.join();
	t2.join();
	t3.join();
	t4.join();

	cout << singleton::getinstance() << endl;
	cout << singleton::getinstance() << endl;
	cout << singleton::getinstance() << endl;
	cout << singleton::getinstance() << endl;

	return 0;
}