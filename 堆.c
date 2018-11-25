////˫�ױ�ʾ������˫�׿죬�Һ�������
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
////���ӱ�ʾ��(�Һ��ӿ죬��˫������
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
////˫�׺��ӱ�ʾ��
//
////�����ֵܱ�ʾ�������ã�


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

// ������ void HeapSort(int* a, int n);

//void TestHeap();
#ifndef _HEAP_H_
#define _HEAP_H_

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int HDataType;
typedef struct Heap
{
	HDataType* _array;//����ָ��̬����ռ��ָ��
	int _capacity;//���鳤��
	int _size;//���ڱ����ʼ��ʱ��̬����ռ�Ĵ�С
}Heap;
void HeapInit(Heap*hp, int capacity);
HeapDestory(Heap* hp);
int EmptyHeap(Heap*hp);
void HeapInsert(Heap*hp, HDataType x);//���x
HPDataType HeapTop(Heap* hp);//ɾ���Ѷ�Ԫ��
#endif

void HeapInit(Heap*hp,int capacity)//��ʼ��
{
	assert(hp);
	hp->_array = (HDataType*)malloc(sizeof(HDataType)*capacity);
	hp->_capacity = capacity;
	hp->_size = 0;
}

HeapDestory(Heap* hp)//ɾ����
{
	assert(hp);
	if (hp->_array != NULL)
	{
		free(hp->_array);
		hp->_size = 0;
		hp->_capacity = 0;
	}
}

int EmptyHeap(Heap*hp)//�п�
{
	assert(hp);
	if (hp->_capacity < 0)
	{
		return 1;
	}
	else
		return 0;
}

void HeapInsert(Heap*hp, HDataType x)//���x
{
	assert(hp);
	int i = 0;
	if (hp->_capacity == hp->_size)//��չ�ռ�Ϊ2��
	{
		HDataType*p = realloc(hp->_array, 2 * hp->_size*sizeof(HDataType*));
		printf("�ռ�����չ\n");
		hp->_array = p;
		hp->_size = 2 * hp->_size;
	}
	hp->_array[hp->_capacity] = x;
	hp->_capacity++;
	i = hp->_capacity - 1;
	while (i != 0)//����λ��
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

HDataType HeapTop(Heap* hp)//ɾ���Ѷ�Ԫ��
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