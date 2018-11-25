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


Squeue *InitQueue()//��ʼ��
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

void DestroySqueue(Squeue *pSqueue)//����
{
	assert(pSqueue);
	if (IsEmpty(pSqueue) != 1)
	{
		ClearSqueue(pSqueue);
	}
	free(pSqueue);
}

void ClearSqueue(Squeue *pSqueue)//���
{
	assert(pSqueue);
	while (IsEmpty(pSqueue) != 1)
	{
		DeQueue(pSqueue, NULL);
	}
}

int IsEmpty(Squeue *pSqueue)//�п�
{
	assert(pSqueue);
	if (pSqueue->head == NULL&&pSqueue->end == NULL&&pSqueue->size == NULL)
	{
		return 1;
	}
	return 0;
}


int GetSize(Squeue *pSqueue)//��ȡ���д�С
{
	assert(pSqueue);
	return pSqueue->size;
}

pNode GetFront(Squeue *pSqueue, Item *pitem)//���ض�ͷԪ��
{
	assert(pSqueue);
	if (IsEmpty(pSqueue) != 1 && pitem != NULL)
	{
		*pitem = pSqueue->end->node;
	}
	return pSqueue->head;
}

pNode GetRear(Squeue *pSqueue, Item *pitem)//���ض�βԪ��
{
	assert(pSqueue);
	if (IsEmpty(pSqueue) != 1 && pitem != NULL)
	{
		*pitem = pSqueue->end->node;
	}
	return pSqueue->end;
}


pNode EnQueue(Squeue *pSqueue, Item item)//����Ԫ�����
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

pNode DeQueue(Squeue *pSqueue, Item *pitem)//��ͷԪ�س���
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
	printf("0-9������Ӳ�������£�\n");
	for (i = 0; i<10; i++)
	{
		EnQueue(pq, i);
		GetRear(pq, &item);
		printf("%d ", item);
	}

	printf("������Ԫ�����γ����в�������£�\n");
	for (i = 0; i<10; i++)
	{
		DeQueue(pq, &item);
		printf("%d ", item);
	}
	ClearSqueue(pq);
	if (IsEmpty(pq))
		printf("\n�������ÿճɹ�\n");
	DestroySqueue(pq);
	printf("�����ѱ�����\n");
	system("pause");
	return 0;
}