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
//
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
	//向上调整建堆  时间复杂度：O(N*logN)
	//for (int i = 1; i < size; i++)
	//{
	//	AdjustUp(a, i);
	//}

	//向下调整建堆  时间复杂度：O(N)
	for (int i = (size - 2) / 2; i >= 0; i--)//size-2 => size-1-1 需要减多一次1找到下标位置
	{
		AdjustDown(a, size, i);
	}

	//向下调整  时间复杂度：O(N*logN)
	for (int i = size - 1; i >= 0; i--)
	{
		Swap(&a[i], &a[0]);
		AdjustDown(a, i, 0);
 	}
}

//Top-K
void PrintTopk(int* a, int n, int k)
{
	//建堆--用前k个建堆（找大值建小堆  找小值建大堆）
	for (int i = (k - 2) / 2; i >= 0; i--)
	{
		AdjustDown(a, k, i);
	}

	//将剩余n-k个元素依此与堆顶元素交换，不满足条件则交换
	for (int i = k; i < n; i++)
	{
		if (a[0] < a[i])
		{
			a[0] = a[i];
			AdjustDown(a, k, 0);
		}
	}
}

void TestTopk()
{
	int n = 10000;
	int* a = (int*)malloc(sizeof(int) * n);
	assert(a);
	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 10000;
	}

	a[1009] = 10000 + 1;
	a[5032] = 10000 + 2;
	a[7382] = 10000 + 3;
	a[3409] = 10000 + 4;
	a[4203] = 10000 + 5;
	a[9930] = 10000 + 6;
	a[230] = 10000 + 7;
	a[504] = 10000 + 8;
	a[15] = 10000 + 9;
	a[489] = 10000 + 10;

	PrintTopk(a, n, 10);
}


//Top-K 文件版
void FilePrintTopk(const char* file, int k)
{
	//取数据建堆
	int* topk = (int*)malloc(sizeof(int) * k);
	assert(topk);

	FILE* fout = fopen(file, "r");
	if (fout == NULL)
	{
		perror("fopen error");
		return;
	}

		//读k个数据
	for (int i = 0; i < k; i++)
	{
		fscanf(fout, "%d", &topk[i]);
	}

		//建小堆
	for (int i = (k - 2) / 2; i >= 0; i--)
	{
		AdjustDown(topk, k, i);
	}

	//将剩余n-k个元素依此与堆顶元素交换，不满足条件则交换
	int val = 0;
	int ret = fscanf(fout, "%d", &val);
	while (ret != EOF)
	{
		if (val > topk[0])
		{
			topk[0] = val;
			AdjustDown(topk, k, 0);
		}
		
		ret = fscanf(fout, "%d", &val);
	}

	free(topk);
	fclose(fout);
}

//造数据
void CreateNData()
{
	int n = 1000;
	srand(time(0));
	const char* file = "data.txt";
	FILE* fin = fopen(file, "w");
	if (fin == NULL)
	{
		perror("fopen fail");
		return;
	}

	for (int i = 0; i < n; i++)
	{
		int x = rand() % 1000;
		fprintf(fin, "%d\n", x);
	}
	fclose(fin);
}

int main()
{
	//int a[10] = { 3,4,2,6,1,0,9,5,8,7 };
	//HeapSort(a, 10);

	//TestTopk();

	//CreateNData();
	FilePrintTopk("data.txt", 10);

	return 0;
}