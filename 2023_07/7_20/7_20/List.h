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

//初始化
//void LTInit(ListNode** pphead);
ListNode* LTInit();
//销毁
void LTDestory(ListNode* phead);
//打印
void LTPrint(ListNode* phead);

//尾插
void LTPushBack(ListNode* phead, LTDataType x);
//尾删
void LTPopBack(ListNode* phead);

//前插
void LTPushFront(ListNode* phead, LTDataType x);
//前删
void LTPopFront(ListNode* phead);

//查找
ListNode* LTFind(ListNode* phead, LTDataType x);
//pos位置前插入
void LTInsert(ListNode* pos, LTDataType x);
//pos位置前删除
void LTErase(ListNode* pos);
