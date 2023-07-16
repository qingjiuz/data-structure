#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLTDateType;

typedef struct SListNode
{
	SLTDateType date;
	struct SListNode* next;
}SListNode;

//打印
void SListPrint(SListNode* plist);

//尾插
void SListPushBack(SListNode** pplist, SLTDateType x);
//头插
void SListPushFront(SListNode** pplist, SLTDateType x);

//尾删
void SListPopBack(SListNode** pplist);
//头删
void SListPopFront(SListNode** pplist);

//查找数据
SListNode* SListFind(SListNode* plist, SLTDateType x);
//在pos之后插入数据
void SListInsertAfter(SListNode* pos, SLTDateType x);
//在pos之后删除数据
void SListEraseAfter(SListNode* pos);

//销毁单链表
void SListDestroy(SListNode* plist);