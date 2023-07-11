#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define Inception 5

typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* a;
	int size;
	int capacity;
}SL;

//基本功能：增删查改

//创建一个顺序表
void SLInit(SL* ps);
//销毁一个顺序表
void SLDestroy(SL* ps);

//打印顺序表
void SLPrint(SL* ps);

//检查容量
void SLChackCapacity(SL* ps);

//尾插/尾删
void SLPushBack(SL* ps, SLDataType x);
void SLPopBack(SL* ps);

//前删/前插
void SLPushFront(SL* ps, SLDataType x);
void SLPopFront(SL* ps);

//中间插入/删除
void SLInsert(SL* ps, int pos, SLDataType x);
void SLErase(SL* ps, int pos);

//查找
int SLFind(SL* ps, SLDataType x);