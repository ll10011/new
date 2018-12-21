#include<iostream>
#include<malloc.h>
using namespace std;
//class test
//{
//public:
//	test()
//		:_data(0)
//	{
//		cout << "test():" << this << endl;
//	}
//	~test()
//	{
//		cout << "~test()" << this << endl;
//	}
//private:
//	int _data;
//};
//
//void test1()
//{
//	test*p1 = (test*)malloc(sizeof(test));
//	free(p1);
//
//	test*p2 = (test*)malloc(sizeof(test)* 10);
//	free(p2);
//}
//
//void test2()
//{
//	test*p1 = new test;
//	delete p1;
//
//	test*p2 = new test[10];
//	delete[] p2;
//}
//int main()
//{
//	test1();
//	test2();
//	return 0;
//}

/*
struct listnode
{
listnode* _next;
listnode* _prev;
int data;

void* operator new(size_t n)
{
void*p = nullptr;
p = allocator<listnode>().allocate(1);
cout << "memory pool allocator" << endl;
return p;
}

void operator delete(void* p)
{
allocator<listnode>().deallocate((listnode*)p, 1);
cout << "memory pool deallocate" << endl;
}
};

class list
{
public:
list()
{
_head = new listnode;
_head->_next = _head;
_head->_prev = _head;
}

~list()
{
listnode* cur = _head->_next;
while (cur != _head)
{
listnode*next = cur->_next;
delete cur;
cur = next;
}
delete _head;
_head = nullptr;
}
private:
listnode*_head;
};

int main()
{
list s;
return 0;
}
*/


class test
{
private:
	int _data;
public:
	test()
		:_data(0)
	{
		cout << "test():" << this << endl;
	}
	~test()
	{
		cout << "~test():" << this << endl;
	}

};

void test1()
{

	test* p = (test*)malloc(sizeof(test));
	new(p) test;
}
int main()
{
	test1();
	return 0;
}