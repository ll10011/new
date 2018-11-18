#ifndef __STACK_H__
#define __STACK_H__
#pragma warning(disable:4996)

#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include<stdlib.h>
#include<Windows.h>

typedef int SDataType;
typedef struct stack
{
	SDataType *_array;
	int _capacity;//有效元素最大个数
	int _top;//栈顶
}Stack;

void StackInit(Stack* ps);
void StackDestory(Stack* ps);
void Stackpush(Stack*ps, SDataType data);
void StackPop(Stack* ps);
SDataType StackTop(Stack* ps);
int StackEmpty(Stack* ps);
int StackSize(Stack* ps);

#endif

void StackInit(Stack* ps)//初始化
{
	assert(ps);
	ps->_array = (SDataType*)malloc(sizeof(SDataType)* 3);
	if (NULL == ps->_array)
		exit(1);

	ps->_capacity = 3;
	ps->_top = 0;
}

void StackDestory(Stack* ps)//销毁
{
	assert(ps);
	if (ps->_array)
	{
		free(ps->_array);
		ps->_array = NULL;
		ps->_capacity = 0;
		ps->_top = 0;
	}
}
void _CheckCapacity(Stack*ps)//增容
{
	assert(ps);
	if (ps->_top == ps->_capacity)
	{
		ps->_array = (SDataType*)realloc(ps->_array, sizeof(SDataType)*(ps->_capacity + 3));
		ps->_capacity <<= 1;
	}
}
void Stackpush(Stack*ps, SDataType data)//压栈
{
	assert(ps);
	_CheckCapacity(ps);
	ps->_array[ps->_top++] = data;
}

void StackPop(Stack* ps)//出栈
{
	assert(ps);
	ps->_top--;
}

SDataType StackTop(Stack* ps)//取栈顶元素
{
	assert(ps);
	return ps->_array[ps->_top - 1];
}

int StackEmpty(Stack* ps)//判空
{
	assert(ps);
	return ps->_top == 0;
}

int StackSize(Stack* ps)//栈的大小
{
	assert(ps);
	return ps->_top;
}

void testStack()
{
	Stack s;
	StackInit(&s);
	Stackpush(&s, 1);
	Stackpush(&s, 2);
	Stackpush(&s, 3);
	Stackpush(&s, 4);

	while (!StackEmpty(&s))
	{
		printf("%d ", StackTop(&s));
		StackPop(&s);
	}

	StackDestory(&s);
}

int main()
{
	testStack();
	system("pause");
	return 0;
}