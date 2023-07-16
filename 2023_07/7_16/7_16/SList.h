#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLTDateType;

typedef struct SListNode
{
	SLTDateType date;
	struct SListNode* next;
}SListNode;

//��ӡ
void SListPrint(SListNode* plist);

//β��
void SListPushBack(SListNode** pplist, SLTDateType x);
//ͷ��
void SListPushFront(SListNode** pplist, SLTDateType x);

//βɾ
void SListPopBack(SListNode** pplist);
//ͷɾ
void SListPopFront(SListNode** pplist);

//��������
SListNode* SListFind(SListNode* plist, SLTDateType x);
//��pos֮���������
void SListInsertAfter(SListNode* pos, SLTDateType x);
//��pos֮��ɾ������
void SListEraseAfter(SListNode* pos);

//���ٵ�����
void SListDestroy(SListNode* plist);