#include "SList.h"

//打印
void SListPrint(SListNode* plist)
{
	SListNode* cur = plist;
	if (cur != NULL)
	{
		while (cur)
		{
			printf("%d->", cur->date);
			cur = cur->next;
		}
	}
	printf("NULL\n");
}

//扩容
static SListNode* BuySListNode(SLTDateType x)
{
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(-1);//强制结束
	}
	newnode->date = x;
	newnode->next = NULL;
	return newnode;
}

//尾插
void SListPushBack(SListNode** pplist, SLTDateType x)
{
	SListNode* newnode = BuySListNode(x);

	if (*pplist == NULL)
	{
		*pplist = newnode;
	}
	else
	{
		//找尾
		SListNode* tail = *pplist;
		while (tail->next)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}

//头插
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	SListNode* newnode = BuySListNode(x);
	newnode->next = *pplist;
	*pplist = newnode;
}

//尾删
void SListPopBack(SListNode** pplist)
{
	assert(*pplist);
	SListNode* tail = *pplist;

	if ((*pplist)->next == NULL)
	{
		*pplist = NULL;
		free(tail);
	}
	else
	{
		//找尾
		while (tail->next->next)
		{
			tail = tail->next;
		}
		free(tail->next);
		tail->next = NULL;

	}
}

//头删
void SListPopFront(SListNode** pplist)
{
	assert(*pplist);

	SListNode* ptr = (*pplist)->next;
	free(*pplist);
	*pplist = ptr;
}

//查找数据
SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	SListNode* cur = plist;
	while (cur)
	{
		if (cur->date == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

//在pos之后插入数据
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	SListNode* newnode = BuySListNode(x);

	newnode->next = pos->next;
	pos->next = newnode;
}

//在pos之后删除数据
void SListEraseAfter(SListNode* pos)
{
	if (pos->next != NULL)
	{
		SListNode* ptr = pos->next->next;
		free(pos->next);
		pos->next = ptr;
	}
	else
	{
		printf("no date behind\n");
	}
}

//销毁单链表
void SListDestroy(SListNode* plist)
{
	SListNode* cur = plist;

	while (cur)
	{
		cur = plist->next;
		free(plist); 
		plist = cur;
	}
}
