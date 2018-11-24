#ifndef __SQUEUE_H__
#define __SQUEUE_H__


#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<Windows.h>

#pragma warning(disable:4996)

typedef int Item;
typedef struct Node*pNode;
typedef struct Node
{
	Item node;
	pNode next;
}Node;
typedef struct Squeue
{
	 int size;
	 pNode head;
	 pNode end;
}Squeue;
Squeue *InitQueue();

void DestroySqueue(Squeue *pSqueue);

void ClearSqueue(Squeue *pSqueue);

int IsEmpty(Squeue *pSqueue);

int GetSize(Squeue *pSqueue);

pNode GetFront(Squeue *pSqueue, Item *pitem);

pNode GetRear(Squeue *pSqueue, Item *pitem);

pNode EnQueue(Squeue *pSqueue, Item item);

pNode DeQueue(Squeue *pSqueue, Item *pitem);

void SqueueTraverse(Squeue *pSqueue, void(*visit)());



#endif


Squeue *InitQueue()//初始化
{
	Squeue*pSqueue = (Squeue*)malloc(sizeof(Squeue));
	if (pSqueue != NULL)
	{
		pSqueue->head =NULL;
		pSqueue->end = NULL;
		pSqueue->size = 0;
	}
	return pSqueue;
}

void DestroySqueue(Squeue *pSqueue)//销毁
{
	assert(pSqueue);
	if (IsEmpty(pSqueue) != 1)
	{
		ClearSqueue(pSqueue);
	}
	free(pSqueue);
}

void ClearSqueue(Squeue *pSqueue)//清空
{
	assert(pSqueue);
	while (IsEmpty(pSqueue) != 1)
	{
		DeQueue(pSqueue, NULL);
	}
}

int IsEmpty(Squeue *pSqueue)//判空
{
	assert(pSqueue);
	if (pSqueue->head == NULL&&pSqueue->end == NULL&&pSqueue->size == NULL)
	{
		return 1;
	}
	return 0;
}


int GetSize(Squeue *pSqueue)//获取队列大小
{
	assert(pSqueue);
	return pSqueue->size;
}

pNode GetFront(Squeue *pSqueue, Item *pitem)//返回队头元素
{
	assert(pSqueue);
	if (IsEmpty(pSqueue) != 1 && pitem != NULL)
	{
		*pitem = pSqueue->end->node;
	}
	return pSqueue->head;
}

pNode GetRear(Squeue *pSqueue, Item *pitem)//返回队尾元素
{
	assert(pSqueue);
	if (IsEmpty(pSqueue) != 1 && pitem != NULL)
	{
		*pitem = pSqueue->end->node;
	}
	return pSqueue->end;
}


pNode EnQueue(Squeue *pSqueue, Item item)//将新元素入队
{
	assert(pSqueue);
	pNode node = (pNode)malloc(sizeof(Node));
	if (node!= NULL)
	{
		node->node = item;
		node->next = NULL;
		if (IsEmpty(pSqueue))
		{
			pSqueue->head = node;
		}
		else
		{
			pSqueue->end->next = node;
		}
		pSqueue->end= node;
		pSqueue->size++;
	}
	return pSqueue->end;
}

pNode DeQueue(Squeue *pSqueue, Item *pitem)//对头元素出队
{
	assert(pSqueue);
	pNode node = pSqueue->head;
	if (IsEmpty(pSqueue) != 1 && node != NULL)
	{
		if (pitem != NULL)
			*pitem = pSqueue->head->node;
		pSqueue->size--;
		pSqueue->head = node->next;
		free(node);
		if (pSqueue->size == 0)
			pSqueue->end = NULL;
	}
	return pSqueue->head;
}
int main()
{
	Squeue *pq = InitQueue();
	int i, item;
	printf("0-9依次入队并输出如下：\n");
	for (i = 0; i<10; i++)
	{
		EnQueue(pq, i);
		GetRear(pq, &item);
		printf("%d ", item);
	}

	printf("队列中元素依次出队列并输出如下：\n");
	for (i = 0; i<10; i++)
	{
		DeQueue(pq, &item);
		printf("%d ", item);
	}
	ClearSqueue(pq);
	if (IsEmpty(pq))
		printf("\n将队列置空成功\n");
	DestroySqueue(pq);
	printf("队列已被销毁\n");
	system("pause");
	return 0;
}