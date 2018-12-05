#include<time.h>
#include<iostream>
using namespace std;
struct A
{
	int a[100000];
};

A a;
A test1()
{
	return a;
}

A& test2()
{
	return a;
}


void test()
{
	size_t begin1 = clock();
	for (int i = 0; i < 100000; i++)
	{
		test1();
	}
	size_t end1 = clock();
	size_t begin2 = clock();
	for (int i = 0; i < 100000; i++)
	{
		test2();
	}
	size_t end2 = clock();

	cout << "test1 time" << end1 - begin1 << endl;
	cout << "test2 time" << end2 - begin2 << endl;
}

int main()
{
	for (int i = 0; i < 10; ++i)
		test();

	return 0;
}
