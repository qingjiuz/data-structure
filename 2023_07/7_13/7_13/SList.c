#include "SList.h"

//��ӡ
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

//����
static SListNode* BuySListNode(SLTDateType x)
{
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(-1);//ǿ�ƽ���
	}
	newnode->date = x;
	newnode->next = NULL;
	return newnode;
}

//β��
void SListPushBack(SListNode** pplist, SLTDateType x)
{
	SListNode* newnode = BuySListNode(x);

	if (*pplist == NULL)
	{
		*pplist = newnode;
	}
	else
	{
		//��β
		SListNode* tail = *pplist;
		while (tail->next)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}

//ͷ��
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	SListNode* newnode = BuySListNode(x);
	newnode->next = *pplist;
	*pplist = newnode;
}

//βɾ
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
		//��β
		while (tail->next->next)
		{
			tail = tail->next;
		}
		free(tail->next);
		tail->next = NULL;

	}
}

//ͷɾ
void SListPopFront(SListNode** pplist)
{
	assert(*pplist);

	SListNode* ptr = (*pplist)->next;
	free(*pplist);
	*pplist = ptr;
}

//��������
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

//��pos֮���������
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	SListNode* newnode = BuySListNode(x);

	newnode->next = pos->next;
	pos->next = newnode;
}

//��pos֮��ɾ������
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

//���ٵ�����
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
