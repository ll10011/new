��д���룬�Ը���ֵxΪ��׼������ָ�������֣�����С��x�Ľ�����ڴ��ڻ����x�Ľ��֮ǰ��

if��pHead == NULL)
return NULL;
ListNode LessHead(0);
ListNode greatHead(0);
pListNode *pListTail = &ListHead;
pListNode *pgreatTail = &greatHead;
ListNode*pcur = pHead;
while (pcur)
{
	if (pcur->val<x)
	{
		pListTail->next = pcur;
		pListTail = pListTail->next;
	}
	else
	{
		pgreatTail->next = pcur;
		pgreatTail = pgreatTail->next;
	}
	pcur = pcur->next;
}
pListTail->next = greatTail.next;
greatTail->next = NULL;
return ListHead;
��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬�ظ��Ľ�㲻��������������ͷ ָ�� :
1.���ظ������ڵ������
2.ɾ���ظ��ڵ�
�Ƿ�Ϊͷ�ڵ�

//���Ϊ��
if (NULL == phead || NULL == phead->next)
return phead;
ListNode*ppre = phead;
ListNode*pcur = phead;
ListNode*pfirst = NULL;
ListNode*plast = NULL;
while (pcur)
{
	pfirst = pcur;
	plast = pcur->next;
	//���ظ��ӽڵ�����
	while (plast)
	{
		if (pcur->val != plast->val)
			break:
		else
		{
			pcur = pcur->next;
			plast = plast->next;
		}
	}
	//������û���ظ�Ԫ��
	if (pfirst->next == plast)
	{
		ppre = pcur;
		pcur = plast;
	}
	else
	{
		if (pfirst == phead)
		{
			while (phead != plast)
			{
				phead = phead->next;
				free(pfirst);
				pfirst = phead;
			}
		}
		else
		{
			ListNode*pdel = pfirst;
			while (pfirst != plast)
			{
				pfirst = pfirst->next;
				free(pdel);
				pdel = pfirst;
			}
			ppre->next = plast;
			pcur = plast;
		}
	}
}
return phead;
����Ļ��Ľṹ:

{
	if��NULL == array��
		return true;
	int* array = (int*)malloc(sizeof(int)* 900);
	if (NULL == array)
		return false;
	ListNode*pcur = array;
	int count = 0;
	while (pcur)
	{
		array[count++] = pcur->val;
		pcur = pcur->next;
	}
	int left = 0
		int right = count - 1;
	while (left < right)
	{
		if (array[left] != array[right])
		{
			break;
		}
		left++;
		right--;
	}
	free(array);
	return true;
}
�������������ҳ����ǵĵ�һ���������:

{
	//����ѭ���Ƚϣ�Ч��̫��<������>��
	�ж����������Ƿ��ཻ(�޻�)
		���ж������������һ���ڵ��Ƿ���ͬ��
		ListNode*IsCross(ListNode*phead1, ListNode2)
	{
			if (NULL == phead || NULLphead2)
				return 0;
			ListNode*ptail1 = phead1;
			ListNode*ptail2 = phead2;
			while (ptile1->next)
				ptile1 = ptail->next;
			while (ptile2->next)
				ptile2 = ptai2->next;
			return ptail1 = ptial2;
		}
}
�������������ҳ����ǵĵ�һ���������:
{
	if (NULL == headA || NULL == headB)
		return Null;
	ListNode*pLA = headA;
	int sizeA = 0;
	while (pLA)
	{
		sizeA++;
		pLA = pLA->next;
	}
	ListNode*pLB = headB;
	int sizeB = 0;
	while (pLB)
	{
		sizeB++;
		pLB = pLB->next;
	}
	int gap = sizeA - sizeB;
	pLA = headA;
	pLB = headB;
	if (gap > 0)
	{
		while (gap--)
			pLA = pLA->next;
	}
	else
	{
		while (gap--)
			pLB = pLB->next;
	}
	while (pLA&&pLB)
	{
		if (pLA == pLB)
			return pLA;
		pLA = pLA->next;
		pLB = pLB->next;
	}
	return 0;
}
����һ�������ж��������Ƿ��л�:

bool hascycle(ListNode*head)
{
	ListNode*fast = head;
	ListNode*slow = head;
	while (pfast&&pfast->next)
	{
		pfast = pfast->next->next;
		pslow = pslow->slow;
		if (pfast = pslow)
			return true;
	}
	return false;
}
����һ��������������ʼ�뻷�ĵ�һ���ڵ㡣 ��������޻����򷵻� NULL
1.ȷ�������Ƿ����
2.����->����ڵ�
���л�pfrist : L + X + r
		pslow : L + X

				------ - 2 * (L + X) = L + X + nr
				------ - L + X = nr
				------ - L = nr - X
				)

{
	ListNode*pfast = head;
	ListNode*pslow = head;
	//�ж������Ƿ����
	while (pfast&&pfast->next)
	{
		pfast = pfast->next->next;
		pslow = pslow->next;
		if (pfast = pslow)
			break;
	}
	//��������
	if (pfast == NULL&&pfast->next == NULL)
		return NULL;
	ListNode*pm = pfast;
	ListNode*ph = head;
	while (pm != ph)
	{
		pm = pm->next;
		ph = ph->next;
	}
	return pm;
}

�����������Ƿ��ཻ������ཻ���ؽ��㣨���ܴ�������
1.����������������
a.�ཻ��y v)
b.���ཻ
2.����ֻ��һ��������
һ�������ཻ
3������������
a.�ཻ{
	�����ڻ��⣻
	�����ڻ��ڣ�
}
b.���ཻ
{
	ListNode*pm1 = hascirele(phead);
	ListNode*pm2 = hascirele(phead);
	//��������������
	//������������
}
����һ������ÿ���ڵ����һ���������ӵ����ָ�룬��ָ�����ָ�������е��κνڵ��սڵ㡣 Ҫ�󷵻�����������ȿ���
1.��ԭ����ÿ���ڵ�����ֵ��ͬ���½ڵ㣻
2.���²���ڵ�����ָ����ֵ��
3.���²���Ľڵ��ԭ�����в�������

{
	struct radomListNode*pNewNode = (struct radomListNode*)malloc(sizeof(struct  radomListNode));
	if (NULL == pNewNode)
		exut(1);
	pNewNode->label = label;
	pNewNode->next = NULL;
	pNewNode->radom = pNewNode;
	if (NULL = head)
		return NULL;
	struct radomListNode*pcur = head;
	struct radomListNode*pNewNode;
	//1.��ԭ����ÿ���ڵ�����ֵ��ͬ���½ڵ㣻
	while (pcur)
	{
		pNewNode = buyListNode(pcur->label);
		pNewNode->next = pcur->next;
		pcur->next = pNewNode;
		pcur = pNewNode->next;
	}
	//2.���²���ڵ�����ָ����ֵ;
	pcur = head;
	while (pcur)
	{
		pNewNode = pcur->next;
		if (NULL == pcur->random)
			pNewNode->random = NULL;
		else
			pNewNode->random = pcur->random->next;
		pcur = pNewNode->next;
	}
	//3.���²���Ľڵ��ԭ�����в�������
	struct radomListNode**pNewHead = head->next;
	pcur = head;
	pNewNode = pcur->next;
	while (pNewNode)
	{
		pcur->next = pNewNode->next;
		pcur = pNewNode;
		pNewNode = pNewNode->next;
	}
	return pNewNode;
}