#include"List.h"

//创建数据
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

//检查链表是否存有数据
bool LTEmpty(ListNode* phead)
{
	assert(phead);
	ListNode* ptail = phead->next;
	return ptail != phead;
}

//初始化
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

//销毁
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

//打印
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

//尾插
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

//尾删
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

//前插
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

//前删
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

//查找
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

//pos位置前插入
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

//删除pos位置节点
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
