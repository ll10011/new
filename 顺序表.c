#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<assert.h>

void InitList(PSeqList ps);  //初始化
int LengthList(PSeqList ps);//求顺序表的长度
int GetData(PSeqList ps, int i);//按序号查找
int InsList(PSeqList ps, int i, datatype x);//插入元素
int DelList(PSeqList ps, datatype i, datatype* x);//删除元素
int Locate(PSeqList ps, datatype x);//按内容查找
void PushFront(PSeqList ps, datatype x);//头插
int EmptyList(PSeqList ps);//判断是否为空
void PopFront(PSeqList ps);//头删
void PopBack(PSeqList ps);//尾删
void PushBack(PSeqList ps, datatype x);//尾插
void ClearList(PSeqList ps);//清空顺序表
void PrintList(PSeqList ps);//打印表中元素
void BubbleSort(PSeqList ps);//冒泡法打印表中元素

#define listsize 100
typedef int datatype;

 typedef struct
{
		datatype data[listsize];   //用数组存储元素
		datatype length;           //顺序表中元素的个数
}SeqList, *PSeqList;

 void InitList(PSeqList ps)   //初始化
 {
	 assert(ps);
	 ps->length = 0;
 }

 int LengthList(PSeqList ps)//求顺序表的长度
 {
	 assert(ps);
	 return ps->length;
 }

 int GetData(PSeqList ps, int i)//按序号查找
 {
	 if (ps->length<1||ps->length>lengthlist(ps))
	 {
		 return 0;
	 }
	 return ps->data[i - 1];
 }

 int InsList(PSeqList ps, int i, datatype x)//插入元素
 {
	 if (ps->length<1 || ps->length>lengthlist(ps))
	 {
		 printf("输入错误\n");
		 return 0;
	 }
	 else if (ps->length >= listsize)
	 {
		 printf("顺序表已满\n");
		 return 0;
	 }
	 else
	 {
		 for (int j = i; i < ps->length; j++)
		 {
			 ps->data[j + 1] = ps->data[j];
		 }
		 ps->data[i - 1] = x;
		 ps->length++;
		 return 1;
	 }
	 return 0;
 }

 int DelList(PSeqList ps, datatype i, datatype* x)//删除元素
 {
	 if (ps->length < 1)
	 {
		 return 0;
	 }
	 *x = ps->data[i - 1];
	 for (int j = i; j < ps->length; j++)
	 {
		 ps->data[j - 1] = ps->data[j];
	 }
	 ps->length--;
	 return*x;	 
 }

 int Locate(PSeqList ps, datatype x)//按内容查找
 {
	 for (int k = 0; k < ps->length; k++)
	 {
		 if (ps->data[k] = x)
		 {
			 return k + 1;
		 }
	 }
	 return 0;
 }


 void PushFront(PSeqList ps, datatype x)//头插
 {
	 if (ps->length == listsize)
	 {
		 printf("插入表已满\n");
		 return 0;
	 }
	 for (int k = ps->length; k > 0; k--)
	 {
		 ps->data[k] = ps->data[k + 1];
	 }
	 ps->data[0] = x;
	 ps->length++;
 }

 int EmptyList(PSeqList ps)//判断是否为空
 {
	 if (ps->length == 0)
	 {
		 return 1;
	 }
	 return 0;
 }

 void PopFront(PSeqList ps)//头删
 {
	 if ( emptylist(ps)== 0)
	 {
		 printf("顺序表为空\n");
	 }
	 for (int k = 0; k < ps->length; k++)
	 {
		 ps->data[k] = ps->data[k - 1];
	 }
	 ps->length--;
 }

 void PopBack(PSeqList ps)//尾删
 {
	 if (empty(ps) == 0)
	 {
		 printflist("顺序表为空\n");
	 }
	 ps->length--;
 }

 void PushBack(PSeqList ps, datatype x)//尾插
 {
	 if (empty(ps) == 0)
	 {
		 printf("顺序表为空\n");
	 }
	 ps->data[ps->length] = x;
	 ps ->length++;
 }

 void ClearList(PSeqList ps)//清空顺序表
 {
	 ps->length = 0;
 }

 void PrintList(PSeqList ps)//打印表中元素
 {
	 if (empty(ps) == 0)
	 {
		 printflist("顺序表为空\n");
	 }
	 for (int j = 0; j < ps->length; j++)
	 {
		 printf("%d 7\n", ps->data[j]);
	 }
 }
 void BubbleSort(PSeqList ps)//冒泡法打印表中元素
 {
	 if (empty(ps) == 0)
	 {
		 printflist("顺序表为空\n");
	 }
	 for (int i = 0; i < ps->length; i++)
	 {
		 for (int j = 0; j < i - 1; j++)
		 {
			 if (ps->data[j] < ps->data[j + 1])
			 {
				 int ret = ps -> data[j];
				 ps->data[j] = ps->data[j + 1];
				 ps->data[j + 1] = ret;
			 }
		 }
	 }
 }
 int main()
 {
	 system("pause");
	 return 0;
 }