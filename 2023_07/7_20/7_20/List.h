#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int LTDataType;

typedef struct ListNode
{
	LTDataType data;

	struct ListNode* prev;
	struct ListNode* next;
}ListNode;

//��ʼ��
//void LTInit(ListNode** pphead);
ListNode* LTInit();
//����
void LTDestory(ListNode* phead);
//��ӡ
void LTPrint(ListNode* phead);

//β��
void LTPushBack(ListNode* phead, LTDataType x);
//βɾ
void LTPopBack(ListNode* phead);

//ǰ��
void LTPushFront(ListNode* phead, LTDataType x);
//ǰɾ
void LTPopFront(ListNode* phead);

//����
ListNode* LTFind(ListNode* phead, LTDataType x);
//posλ��ǰ����
void LTInsert(ListNode* pos, LTDataType x);
//posλ��ǰɾ��
void LTErase(ListNode* pos);
