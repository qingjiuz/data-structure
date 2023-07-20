#include"List.h"

//��������
ListNode* BuyListNode(LTDataType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		return NULL;
	}
	newnode->data = x;
	newnode->prev = NULL;
	newnode->next = NULL;
	return newnode;
}

//��������Ƿ��������
bool LTEmpty(ListNode* phead)
{
	assert(phead);
	ListNode* ptail = phead->next;
	return ptail != phead;
}

//��ʼ��
//void LTInit(ListNode** pphead)
//{
//	ListNode* newnode = BuyListNode(-1);
//	newnode->next = newnode;
//	newnode->prev = newnode;
//	*pphead = newnode;
//}

ListNode* LTInit()
{
	ListNode* newnode = BuyListNode(-1);
	newnode->prev = newnode;
	newnode->next = newnode;
	return newnode;
}

//����
void LTDestory(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead;
	//while (cur != phead)
	//{
	//	//LTPopBack(cur->prev);
	//	LTErase(cur->prev);
	//}

	phead->prev->next = NULL;
	while (cur)
	{
		cur = phead->next;
		free(phead);
		phead = cur;
	}
}

//��ӡ
void LTPrint(ListNode* phead)
{
	ListNode* cur = phead->next;
	printf("<=>head<=>");
	while (cur != phead)
	{
		printf("%d<=>", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

//β��
void LTPushBack(ListNode* phead, LTDataType x)
{
	assert(phead);

	//ListNode* newnode = BuyListNode(x);
	//ListNode* ptail = phead->prev;
	//ptail->next = newnode;
	//phead->prev = newnode;
	//newnode->prev = ptail;
	//newnode->next = phead;

	LTInsert(phead, x);
}

//βɾ
void LTPopBack(ListNode* phead)
{
	assert(phead);
	assert(LTEmpty(phead));

	//ListNode* ptail = phead->prev;
	//phead->prev = ptail->prev;
	//phead->prev->next = phead;
	//free(ptail);
	//ptail = NULL;
	
	LTErase(phead->prev);
}

//ǰ��
void LTPushFront(ListNode* phead, LTDataType x)
{
	assert(phead);

	//ListNode* newnode = BuyListNode(x);
	//ListNode* tmp = phead->next;
	//phead->next = newnode;
	//tmp->prev = newnode;
	//newnode->prev = phead;
	//newnode->next = tmp;

	LTInsert(phead->next, x);
}

//ǰɾ
void LTPopFront(ListNode* phead)
{
	assert(phead);
	assert(LTEmpty(phead));

	//ListNode* cur = phead->next;
	//phead->next = cur->next;
	//cur->next->prev = phead;
	//free(cur);
	//cur = NULL;

	LTErase(phead->next);
}

//����
ListNode* LTFind(ListNode* phead, LTDataType x)
{
	assert(phead);

	ListNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
			return cur;
		cur = cur->next;
	}
	return NULL;
}

//posλ��ǰ����
void LTInsert(ListNode* pos, LTDataType x)
{
	assert(pos);

	ListNode* newnode = BuyListNode(x);
	ListNode* tmp = pos->prev;
	pos->prev = newnode;
	tmp->next = newnode;
	newnode->next = pos;
	newnode->prev = tmp;
}

//ɾ��posλ�ýڵ�
void LTErase(ListNode* pos)
{
	assert(pos);

	ListNode* PosPrve = pos->prev;
	ListNode* PosNext = pos->next;
	PosPrve->next = PosNext;
	PosNext->prev = PosPrve;
	free(pos);
	pos = NULL;
}
