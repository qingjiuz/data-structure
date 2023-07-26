#include"Heap.h"

//int main()
//{
//	HP hp;
//	HeapInit(&hp);
//
//	HeapPush(&hp, 1);
//	HeapPush(&hp, 3);
//	HeapPush(&hp, 7);
//	HeapPush(&hp, 2);
//	HeapPush(&hp, 5);
//	HeapPush(&hp, 9);
//	HeapPush(&hp, 0);
//
// 
//	//TOP-K
//	int k = 0;
//	scanf("%d", &k);
//	while (!HeapEmpty(&hp) && k--)
//	{
//		printf("%d ", HeapTop(&hp));
//		HeapPop(&hp);
//	}
//
//	HeapDsetroy(&hp);
//
//	return 0;
//}


//排升序-建大堆    排降序-建小堆 （调整向上、向下调整的比较符号）
void HeapSort(HeapDataType* a, int size)
{
	//向上调整
	for (int i = 1; i < size; i++)
	{
		AdjustUp(a, i);
	}

	//向下调整
	for (int i = size - 1; i >= 0; i--)
	{
		Swap(&a[i], &a[0]);
		AdjustDown(a, i, 0);
 	}
}

int main()
{
	int a[10] = { 3,4,2,6,1,0,9,5,8,7 };
	HeapSort(a, 10);

	return 0;
}