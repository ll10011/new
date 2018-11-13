#pragma once
#include<stdio.h>
#include<assert.h>
// 带头结点循环双向链表
typedef int DLDataType;

typedef struct DListNode
{
	struct DListNode* _pNext;
	struct DListNode* _pPre;
	DLDataType _data;
}DListNode;

typedef struct DList
{
	struct DListNode* _pHead;
}DList;

void ListInit(DList* plist);
void ListDestory(DList* plist);
void ListPrint(DListNode* plist);
void ListPushBack(DList* plist, DLDataType x);
void ListPopBack(DList* plist);
void ListPushFront(DList* plist, DLDataType x);
void ListPopFront(DList* plist);
DListNode* ListFind(DList* plist, DLDataType x);
void ListInsert(DListNode* pos, DLDataType x);
void ListErase(DListNode* pos);
void ListRemove(DList* plist, DLDataType x);
void ListRemoveAll(DList* plist, DLDataType x);


void TestDList1();


DListNode* BuyDListNode(DLDataType x)//创建新节点
{
	DListNode* newNode = (DListNode*)malloc(sizeof(DListNode));
	if (newNode == NULL)
	{
		printf("创建失败\n");
	}
	newNode->_data = x;
	newNode->_pNext = NULL;
	newNode->_pPre = NULL;
	return newNode;
}

void ListInit(DList* plist)//初始化
{
	assert(plist);
	DListNode* head = (DListNode*)malloc(sizeof(DListNode*));
	if (head == NULL)
	{
		return NULL;
	}
	head->_pNext = head;
	head->_pPre = head;
	return head;
}

void ListDestory(DList* plist)//删除链表
{
	assert(plist);
	DListNode*cur = plist->_pHead;
	DListNode*next = plist->_pHead;
	if (plist == NULL)
	{
		return NULL;
	}
	while (next)
	{
		cur = next;
		next = next->_pNext;
		free(cur);
		cur = NULL;
	}
	plist = NULL;
}

void ListPrint(DList* plist)//打印链表
{
	assert(plist);
	DListNode*next = plist->_pHead->_pNext;
	if (plist == NULL)
	{
		return NULL;
	}
	while (next != plist->_pHead)
	{
		printf("%d->", next->_data);
		next = next->_pNext;
	}
	printf("head\n");
}


void ListPushFront(DList* plist, DLDataType x)//头插
{
	assert(plist);
	DListNode*newnode = BuyDListNode(x);
	DListNode*next = plist->_pHead->_pNext;
	newnode->_pNext = next;
	next->_pPre = newnode;
	newnode->_pPre = plist->_pHead;
	plist->_pHead->_pNext = newnode;
}

void ListPopFront(DList* plist)//头删
{
	assert(plist);
	DListNode*next1 = plist->_pHead->_pNext;
	DListNode*next2 = next1->_pNext;
	plist->_pHead->_pNext = next2;
	next2->_pPre = plist->_pHead;
	free(next1);
}

void ListPushBack(DList* plist, DLDataType x)//尾插
{
	assert(plist);
	DListNode*newnode = BuyDListNode(x);
	DListNode*pre = plist->_pHead->_pPre;
	newnode->_pNext = plist->_pHead;
	newnode->_pPre = pre;
	pre->_pNext = newnode;
	plist->_pHead->_pPre = newnode;
}
void ListPopBack(DList* plist)//尾删
{
	assert(plist);
	DListNode*pre1 = plist->_pHead->_pPre;
	DListNode*pre2 = pre1->_pPre;
	pre2->_pNext = plist->_pHead;
	plist->_pHead->_pNext = pre2;
	free(pre1);
}
DListNode* ListFind(DList* plist, DLDataType x)//查找链表中的元素
{
	assert(plist);
	if (plist->_pHead == NULL)
	{
		return NULL;
	}
	DListNode*pcur = plist->_pHead->_pNext;
	while (pcur != (plist->_pHead))
	{
		if (pcur->_data == x)
		{
			return pcur;
		}
		pcur = pcur->_pNext;
	}
	return NULL;
}
void ListInsert(DListNode* pos, DLDataType x)//在pos前边插入元素
{
	assert(pos);
	DListNode*pre = pos->_pPre;
	DListNode*newnode = BuyDListNode(x);
	pre->_pNext = newnode;
	newnode->_pPre = pre;
	newnode->_pNext = pos;
	pos->_pPre = newnode;
}

void ListErase(DListNode* pos)//删除Pos位置节点
{
	assert(pos);
	if (pos == pos->_pNext)
	{
		return NULL;
	}
	else
	{
		DListNode*next = pos->_pNext;
		DListNode*pre = pos->_pPre;
		pre->_pNext = next;
		pre->_pPre = pre;
		free(pos);
		pos = NULL;
	}
}

void ListRemove(DList* plist, DLDataType x)//删除值为x元素
{
	assert(plist);
	DListNode*pcur = plist->_pHead->_pNext;
	while (pcur != (plist->_pHead))
	{
		if (pcur->_data == x)
		{
			DListNode*tmp = pcur->_pPre;
			tmp = pcur->_pNext;
			pcur->_pNext->_pNext = tmp;
			free(pcur);
			pcur = NULL;
			return NULL;
		}
		else
		{
			pcur = pcur->_pNext;
		}
	}
}

void ListRemoveAll(DList* plist, DLDataType x)//删除所有值位x的元素
{
	assert(plist);
	DListNode*pcur = plist->_pHead->_pNext;
	while (pcur != (plist->_pHead))
	{
		if (pcur->_data == x)
		{
			DListNode*tmp = pcur->_pPre;
			tmp = pcur->_pNext;
			pcur->_pNext->_pNext = tmp;
			free(pcur);
			pcur = tmp->_pNext;
		}
		else
		{
			pcur = pcur->_pNext;
		}
	}
}

int ListSize(DList* plist)//链表长度
{
	assert(plist);
	int count = 0;
	DListNode*cur = plist->_pHead->_pNext;
	while (cur != (plist->_pHead))
	{
		count++;
		cur = cur->_pNext;
	}
	return cur;
}

int ListEmpty(DList* plist)//链表置空
{
	assert(plist);
	return plist->_pHead = plist->_pHead->_pNext;
}

void TestDList1()
{
	List dl;
	ListInit(&dl);
}
