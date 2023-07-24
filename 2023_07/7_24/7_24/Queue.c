#include"Queue.h"

//��ʼ������
void QueueInit(Queue* pq)
{
	pq->head = pq->tail = NULL;
	pq->data = 0;
}

//��β���
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

//��ͷ����
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	QListNode* next = pq->head;
	pq->head = next->next;
	free(next);
	pq->data--;
}

//��ȡ��ͷԪ��
QueueDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->head->data;
}

//��ȡ��βԪ��
QueueDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->tail->data;
}

//��ȡ��������ЧԪ�ظ���
int QueueSize(Queue* pq)
{
	assert(pq);

	return pq->data;
}

//�������Ƿ�Ϊ�գ�Ϊ�շ���true/���㣬Ϊ�ǿշ���false/0
int QueueEmpty(Queue* pq)
{
	assert(pq);

	return !pq->data;
}

//���ٶ���
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
