#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int QueueDataType;

typedef struct QListNode
{
	QueueDataType data;
	struct QListNode* next;
}QListNode;

typedef struct Queue
{
	QListNode* head;
	QListNode* tail;
	int data;
}Queue;

//初始化队列
void QueueInit(Queue* pq);

//队尾入队
void QueuePush(Queue* pq, QueueDataType x);

//队头出队
void QueuePop(Queue* pq);

//获取队头元素
QueueDataType QueueFront(Queue* pq);

//获取队尾元素
QueueDataType QueueBack(Queue* pq);

//获取队列中有效元素个数
int QueueSize(Queue* pq);

//检测队列是否为空，为空返回true/非零，为非空返回false/0
int QueueEmpty(Queue* pq);

//销毁队列
void QueueDestroy(Queue* pq);
