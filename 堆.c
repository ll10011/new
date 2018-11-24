////双亲表示法（找双亲快，找孩子慢）
//struct TreeNode
//{
//	int data;
//	TreeNode* _pParent;
//};
//
//struct TreeNode
//{
//	int data;
//	int parent;
//};
//
//////////////////////////////////////////////////
//
////孩子表示法(找孩子快，找双亲慢）
//struct TreeNode
//{
//	int data;
//	TreeNode*pchild1;
//	TreeNode*pchild2;
//	TreeNode*pchild3;
//};
//
//struct TreeNode
//{
//	int data;
//	int child1;
//	int child2;
//	int child3;
//};
//
//////////////////////////////////////////////////////
////双亲孩子表示法
//
////孩子兄弟表示法（常用）


//typedef struct Heap
//{ 
//	HPDataType* _a;    
//	int _size;    
//	int _capacity; 
//}Heap;
//
//void HeapInit(Heap* hp, HPDataType* a, int n); 
//void HeapDestory(Heap* hp); 
//void HeapPush(Heap* hp, HPDataType x); 
//void HeapPop(Heap* hp); 
//HPDataType HeapTop(Heap* hp); 
//int HeapSize(Heap* hp); 
//int HeapEmpty(Heap* hp);

// 堆排序 void HeapSort(int* a, int n);

//void TestHeap();
#ifndef _HEAP_H_
#define _HEAP_H_

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int HDataType;
typedef struct Heap
{
	HDataType* _array;//定义指向动态数组空间的指针
	int _capacity;//数组长度
	int _size;//用于保存初始化时动态数组空间的大小
}Heap;
void HeapInit(Heap*hp, int capacity);
HeapDestory(Heap* hp);
int EmptyHeap(Heap*hp);
void HeapInsert(Heap*hp, HDataType x);//添加x
HPDataType HeapTop(Heap* hp);//删除堆顶元素
#endif

void HeapInit(Heap*hp,int capacity)//初始化
{
	assert(hp);
	hp->_array = (HDataType*)malloc(sizeof(HDataType)*capacity);
	hp->_capacity = capacity;
	hp->_size = 0;
}

HeapDestory(Heap* hp)//删除堆
{
	assert(hp);
	if (hp->_array != NULL)
	{
		free(hp->_array);
		hp->_size = 0;
		hp->_capacity = 0;
	}
}

int EmptyHeap(Heap*hp)//判空
{
	assert(hp);
	if (hp->_capacity < 0)
	{
		return 1;
	}
	else
		return 0;
}

void HeapInsert(Heap*hp, HDataType x)//添加x
{
	assert(hp);
	int i = 0;
	if (hp->_capacity == hp->_size)//扩展空间为2倍
	{
		HDataType*p = realloc(hp->_array, 2 * hp->_size*sizeof(HDataType*));
		printf("空间以扩展\n");
		hp->_array = p;
		hp->_size = 2 * hp->_size;
	}
	hp->_array[hp->_capacity] = x;
	hp->_capacity++;
	i = hp->_capacity - 1;
	while (i != 0)//调整位置
	{
		int j = (i - 1) / 2;
		if (x > hp->_array[j])
			break;
		else
			hp->_array[i] = hp->_array[j];
		i = j;
	}
	hp->_array[i] = x;
}

HDataType HeapTop(Heap* hp)//删除堆顶元素
{
	HDataType temp = 0;
	HDataType x = 0;
	int i = 0;
	int j = 0;
	assert(hp);
	if (hp->_capacity == 0)
		return NULL;
	temp = hp->_array[0];
	hp->_capacity--;
	j = 2 * i + 1;
	while (j < hp->_capacity - 1)
	{
		if (hp->_array[j]>hp->_array[j + 1])
			j++;
		if (x <= hp->_array[j])
			break;
		hp->_array[i] = hp->_array[j];
		i = j;
		j = 2 * i + 1;
	}
	hp->_array[i] = x;
	return temp;
}

int main()
{
	int i = 0;
	int x = 0;
	int a[8] = { 1, 3, 5, 7, 9, 2, 4, 6 };
	Heap p;
	HeapInit(&p, 5);
	for (i = 0; i < 8; i++)
	{
		HeapInsert(&p, a[i]);
	}
	while (!HeapDestory(&p))
	{
		x = HeapTop(&p);
		printf("%d", x);
		if (!HeapDestory(&p))
			printf(".");
	}
	printf("\n");
	HeapDestory(&p);
	return 0;
}