编写代码，以给定值x为基准将链表分割成两部分，所有小于x的结点排在大于或等于x的结点之前：

if（pHead == NULL)
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
在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头 指针 :
1.找重复连续节点的区间
2.删除重复节点
是否为头节点

//如果为空
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
	//找重复接节点区间
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
	//区间中没有重复元素
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
链表的回文结构:

{
	if（NULL == array）
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
输入两个链表，找出它们的第一个公共结点:

{
	//可以循环比较（效率太低<不建议>）
	判断两个链表是否相交(无环)
		（判断两个链表最后一个节点是否相同）
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
输入两个链表，找出它们的第一个公共结点:
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
给定一个链表，判断链表中是否有环:

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
给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 NULL
1.确定链表是否带环
2.带环->求入口点
（判环pfrist : L + X + r
		pslow : L + X

				------ - 2 * (L + X) = L + X + nr
				------ - L + X = nr
				------ - L = nr - X
				)

{
	ListNode*pfast = head;
	ListNode*pslow = head;
	//判断链表是否带环
	while (pfast&&pfast->next)
	{
		pfast = pfast->next->next;
		pslow = pslow->next;
		if (pfast = pslow)
			break;
	}
	//链表不带环
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

两个单链表是否相交，如果相交返回交点（可能带环）：
1.两个链表都不带环；
a.相交（y v)
b.不相交
2.两个只有一个带环；
一定不会相交
3两个都带环；
a.相交{
	交点在环外；
	交点在环内；
}
b.不相交
{
	ListNode*pm1 = hascirele(phead);
	ListNode*pm2 = hascirele(phead);
	//两个链表都不带环
	//两个链表都带环
}
给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。 要求返回这个链表的深度拷贝
1.在原链表每个节点后插入值相同的新节点；
2.给新插入节点的随机指针域赋值；
3.将新插入的节点从原链表中拆下来；

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
	//1.在原链表每个节点后插入值相同的新节点；
	while (pcur)
	{
		pNewNode = buyListNode(pcur->label);
		pNewNode->next = pcur->next;
		pcur->next = pNewNode;
		pcur = pNewNode->next;
	}
	//2.给新插入节点的随机指针域赋值;
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
	//3.将新插入的节点从原链表中拆下来；
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