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

//��ʼ������
void QueueInit(Queue* pq);

//��β���
void QueuePush(Queue* pq, QueueDataType x);

//��ͷ����
void QueuePop(Queue* pq);

//��ȡ��ͷԪ��
QueueDataType QueueFront(Queue* pq);

//��ȡ��βԪ��
QueueDataType QueueBack(Queue* pq);

//��ȡ��������ЧԪ�ظ���
int QueueSize(Queue* pq);

//�������Ƿ�Ϊ�գ�Ϊ�շ���true/���㣬Ϊ�ǿշ���false/0
int QueueEmpty(Queue* pq);

//���ٶ���
void QueueDestroy(Queue* pq);
