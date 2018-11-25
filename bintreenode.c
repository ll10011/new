#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct bintreenode
{
	char id;
	struct bintreenode*left;
	struct bintreenode*right;
};

struct queue_node
{
	struct bintreenode*treenode;
	struct queue_node*next;
};

struct queue
{
	struct queue_node*front;
	struct queue_node*rear;
};

typedef struct bintreenode TreeNode;
typedef	struct bintreenode*Tree;
typedef	struct queue_node QueueNode;
typedef	struct queue Queue;

void BuildTree(Tree*T);
int HighTree(Tree T);
int IsMax(int a, int b);
int numbertree(Tree T);
void fronttree(Tree T);
void midtree(Tree T);
void backtree(Tree T);
void leveltree(Tree T);
void InitQueue(Queue*q);
int IsQueueEmpty(Queue*q);
void InQueue(Queue*q, QueueNode *p);
void OutQueue(Queue*q, QueueNode**P);
void clearTree(Tree *T);
int IsTreeEmpty(Tree T);

void BuildTree(Tree*T)//创建二叉树
{
	assert(T);
	char ch;

	scanf("%c ", &ch);
	if (ch == '*')
	{
		*T = NULL;
	}
	else
	{
		*T = (Tree)malloc(sizeof(TreeNode));
		(*T)->id = ch;
		BuildTree(&(*T)->left);
		BuildTree(&(*T)->right);
	}
}
	
int HighTree(Tree T)//求二叉树高度
{

	assert(T);
	if (T == NULL)
	{
		return 0;
	}
	else
	{
		return IsMax(HighTree(T->left), HighTree(T->right)) + 1;
	}
}

int IsMax(int a, int b)
{
	if (a >= b)
	{
		return a;
	}
	else
	{
		return b;
	}
}


int numbertree(Tree T)//求节点个数
{
	assert(T);
	if (NULL == T)
	{
		return 0;
	}
	else
	{
		return numbertree(T->left) + numbertree(T->right) + 1;
	}
}


void fronttree(Tree T)//前序遍历
{
	assert(T);
	if (T != NULL)
	{
		printf("%c ", T->id);
		fronttree(T->left);
		fronttree(T->right);
	}
}

void midtree(Tree T)//中序遍历
{
	assert(T);
	if (T != NULL)
	{
		midtree(T->left);
		printf("%c ", T->id);
		midtree(T->right);
	}
}

void backtree(Tree T)//后序遍历
{
	assert(T);
	if (T != NULL)
	{
		backtree(T->left);
		backtree(T->right);
		printf("%c ", T->id);
	}
}

void InitQueue(Queue*q)//初始化队列
{
	assert(q);
	q->front = NULL;
	q->rear = NULL;
}

int IsQueueEmpty(Queue*q)//判空
{
	assert(q);
	if (q->front)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void InQueue(Queue*q, QueueNode *p)//根节点进入队列
{
	assert(q);
	assert(p);
	if (1==IsQueueEmpty(q))
	{
		q->front = p;
		q->rear = p;
	}
	else
	{
		q->rear->next = p;
		q->rear = p;
	}
}

void OutQueue(Queue*q, QueueNode**P)//当前队首节点出队
{
	p = q->front;
	if (q->front == p->rear)//只有一个节点
	{
		q->front = NULL;
		q->rear = NULL;
	}
	else
	{
		q->front = q->front->next;
	}
}

void leveltree(Tree T)//层序遍历
{
	assert(T);
	if (NULL == T)
	{
		return;
	}
	else
	{
		Queue m_queue;
		Queue *Q;
		QueueNode *p, *q;

		Q = &m_queue;
		InitQueue(Q);//初始化队列

		p = (QueueNode*)malloc(sizeof(QueueNode));
		p->next = NULL;
		p->treenode = T;
		InQueue(Q, p);//根节点进入队列

		while (NULL != IsQueueEmpty(Q))
		{
			OutQueue(Q, &q);//当前队首节点出队
			printf("%c ", q->treenode->id);

			if (q->treenode->left)//左孩子非空
			{
				p = (QueueNode*)malloc(sizeof(QueueNode));
				p->next = NULL;
				p->treenode = q->treenode->left;
				InitQueue(Q, p);
			}
			if (q->treenode->right)//右孩子非空
			{
				p = (QueueNode*)mallloc(sizeof(QueueNode));
				p->treenode = q->treenode->right;
				InitQueue(Q, p);
			}
		}
	}
}
void cleartree(Tree *T)//清楚二叉树
{
	if (*T == NULL)
	{
		return;
	}
	cleartree(&(*T)->left);
	cleartree(&(*T)->right);
	free(*T);
	*T = NULL;
}

int IsTreeEmpty(Tree T)//二叉树判空
{
	if (T)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}