#include"Heap.h"

//初始化堆
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

//销毁堆
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

//向上调整(除了child位置，前面数据构成堆)
void AdjustUp(HeapDataType* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] > a[parent])//>:建大堆  <:建小堆
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

//插入数据
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

//向下调整(左右子树都是大堆/小堆)
void AdjustDown(HeapDataType* a, int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && a[child] < a[child + 1])//<:建大堆 >:建小堆
		{
			child++;
		}

		if (a[parent] < a[child])//<:建大堆 >:建小堆
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

//删除堆顶数据
void HeapPop(HP* php)
{
	assert(php);
	assert(php->size);

	Swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;
	AdjustDown(php->a, php->size, 0);
}

//堆的判空
bool HeapEmpty(HP* php)
{
	assert(php);

	return php->size == 0;
}

//堆顶数据
HeapDataType HeapTop(HP* php)
{
	assert(php);

	return php->a[0];
}

//堆的数据个数
int HeapSize(HP* php)
{
	assert(php);

	return php->size;
}