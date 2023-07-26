#include"Heap.h"

//��ʼ����
void HeapInit(HP* php)
{
	assert(php);

	HeapDataType* ptr = (HeapDataType*)malloc(sizeof(HeapDataType) * 4);
	if (ptr == NULL)
	{
		perror("malloc fail");
		return;
	}

	php->a = ptr;
	php->capacity = 4;
	php->size = 0;
}

//���ٶ�
void HeapDsetroy(HP* php)
{
	assert(php);

	free(php->a);
}

void Swap(HeapDataType* p1, HeapDataType* p2)
{
	HeapDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//���ϵ���(����childλ�ã�ǰ�����ݹ��ɶ�)
void AdjustUp(HeapDataType* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] > a[parent])//>:�����  <:��С��
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

//��������
void HeapPush(HP* php, HeapDataType x)
{
	assert(php);

	if (php->size == php->capacity)
	{
		HeapDataType* ptr = (HeapDataType*)realloc(php->a, sizeof(HeapDataType) * php->capacity * 2);
		if (ptr == NULL)
		{
			perror("realloc fail");
			return;
		}
		php->a = ptr;
		php->capacity *= 2;
	}

	php->a[php->size] = x;
	php->size++;

	AdjustUp(php->a, php->size - 1);
}

//���µ���(�����������Ǵ��/С��)
void AdjustDown(HeapDataType* a, int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && a[child] < a[child + 1])//<:����� >:��С��
		{
			child++;
		}

		if (a[parent] < a[child])//<:����� >:��С��
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

//ɾ���Ѷ�����
void HeapPop(HP* php)
{
	assert(php);
	assert(php->size);

	Swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;
	AdjustDown(php->a, php->size, 0);
}

//�ѵ��п�
bool HeapEmpty(HP* php)
{
	assert(php);

	return php->size == 0;
}

//�Ѷ�����
HeapDataType HeapTop(HP* php)
{
	assert(php);

	return php->a[0];
}

//�ѵ����ݸ���
int HeapSize(HP* php)
{
	assert(php);

	return php->size;
}