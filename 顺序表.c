#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<assert.h>

void InitList(PSeqList ps);  //��ʼ��
int LengthList(PSeqList ps);//��˳���ĳ���
int GetData(PSeqList ps, int i);//����Ų���
int InsList(PSeqList ps, int i, datatype x);//����Ԫ��
int DelList(PSeqList ps, datatype i, datatype* x);//ɾ��Ԫ��
int Locate(PSeqList ps, datatype x);//�����ݲ���
void PushFront(PSeqList ps, datatype x);//ͷ��
int EmptyList(PSeqList ps);//�ж��Ƿ�Ϊ��
void PopFront(PSeqList ps);//ͷɾ
void PopBack(PSeqList ps);//βɾ
void PushBack(PSeqList ps, datatype x);//β��
void ClearList(PSeqList ps);//���˳���
void PrintList(PSeqList ps);//��ӡ����Ԫ��
void BubbleSort(PSeqList ps);//ð�ݷ���ӡ����Ԫ��

#define listsize 100
typedef int datatype;

 typedef struct
{
		datatype data[listsize];   //������洢Ԫ��
		datatype length;           //˳�����Ԫ�صĸ���
}SeqList, *PSeqList;

 void InitList(PSeqList ps)   //��ʼ��
 {
	 assert(ps);
	 ps->length = 0;
 }

 int LengthList(PSeqList ps)//��˳���ĳ���
 {
	 assert(ps);
	 return ps->length;
 }

 int GetData(PSeqList ps, int i)//����Ų���
 {
	 if (ps->length<1||ps->length>lengthlist(ps))
	 {
		 return 0;
	 }
	 return ps->data[i - 1];
 }

 int InsList(PSeqList ps, int i, datatype x)//����Ԫ��
 {
	 if (ps->length<1 || ps->length>lengthlist(ps))
	 {
		 printf("�������\n");
		 return 0;
	 }
	 else if (ps->length >= listsize)
	 {
		 printf("˳�������\n");
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

 int DelList(PSeqList ps, datatype i, datatype* x)//ɾ��Ԫ��
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

 int Locate(PSeqList ps, datatype x)//�����ݲ���
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


 void PushFront(PSeqList ps, datatype x)//ͷ��
 {
	 if (ps->length == listsize)
	 {
		 printf("���������\n");
		 return 0;
	 }
	 for (int k = ps->length; k > 0; k--)
	 {
		 ps->data[k] = ps->data[k + 1];
	 }
	 ps->data[0] = x;
	 ps->length++;
 }

 int EmptyList(PSeqList ps)//�ж��Ƿ�Ϊ��
 {
	 if (ps->length == 0)
	 {
		 return 1;
	 }
	 return 0;
 }

 void PopFront(PSeqList ps)//ͷɾ
 {
	 if ( emptylist(ps)== 0)
	 {
		 printf("˳���Ϊ��\n");
	 }
	 for (int k = 0; k < ps->length; k++)
	 {
		 ps->data[k] = ps->data[k - 1];
	 }
	 ps->length--;
 }

 void PopBack(PSeqList ps)//βɾ
 {
	 if (empty(ps) == 0)
	 {
		 printflist("˳���Ϊ��\n");
	 }
	 ps->length--;
 }

 void PushBack(PSeqList ps, datatype x)//β��
 {
	 if (empty(ps) == 0)
	 {
		 printf("˳���Ϊ��\n");
	 }
	 ps->data[ps->length] = x;
	 ps ->length++;
 }

 void ClearList(PSeqList ps)//���˳���
 {
	 ps->length = 0;
 }

 void PrintList(PSeqList ps)//��ӡ����Ԫ��
 {
	 if (empty(ps) == 0)
	 {
		 printflist("˳���Ϊ��\n");
	 }
	 for (int j = 0; j < ps->length; j++)
	 {
		 printf("%d 7\n", ps->data[j]);
	 }
 }
 void BubbleSort(PSeqList ps)//ð�ݷ���ӡ����Ԫ��
 {
	 if (empty(ps) == 0)
	 {
		 printflist("˳���Ϊ��\n");
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