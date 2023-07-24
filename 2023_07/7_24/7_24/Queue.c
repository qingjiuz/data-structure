#include"Queue.h"

//初始化队列
void QueueInit(Queue* pq)
{
	pq->head = pq->tail = NULL;
	pq->data = 0;
}

//队尾入队
void QueuePush(Queue* pq, QueueDataType x)
{
	QListNode* newnode = (QListNode*)malloc(sizeof(QListNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;

	if (!QueueEmpty(pq))
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
	else
	{
		pq->head = pq->tail = newnode;
	}
	pq->data++;
}

//队头出队
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	QListNode* next = pq->head;
	pq->head = next->next;
	free(next);
	pq->data--;
}

//获取队头元素
QueueDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->head->data;
}

//获取队尾元素
QueueDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->tail->data;
}

//获取队列中有效元素个数
int QueueSize(Queue* pq)
{
	assert(pq);

	return pq->data;
}

//检测队列是否为空，为空返回true/非零，为非空返回false/0
int QueueEmpty(Queue* pq)
{
	assert(pq);

	return !pq->data;
}

//销毁队列
void QueueDestroy(Queue* pq)
{
	assert(pq);

	QListNode* cur = pq->head;
	while (cur)
	{
		pq->head = cur->next;
		free(cur);
		cur = pq->head;
	}
	pq->tail = NULL;
}
