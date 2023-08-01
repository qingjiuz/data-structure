#include"Sort.h"

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}


//选择排序
void SelectSort(int* a, int n)
{
	//for (int j = 0; j < n; j++)
	//{
	//	int left = j;
	//	int mini = j;

	//	//找最小值，与left交换
	//	for (int i = j + 1; i < n; i++)
	//	{
	//		if (a[mini] > a[i])
	//		{
	//			mini = i;
	//		}
	//	}
	//	swap(&a[mini], &a[left]);
	//}

	//优化版本

	//for (int j = 0; j < n; j++)//排序完后依旧会存在循环的情况
	//{
	//	//每次循环都缩小一次区间
	//	int mini = j, maxi = n - j - 1;
	//	int left = mini, right = maxi;

	int left = 0, right = n - 1;
	while(left < right)
	{
		int mini = left, maxi = right;//区间
		for (int i = 1 + left; i <= right; i++)
		{
			//找最小
			if (a[mini] > a[i])
				mini = i;

			//找最大
			if (a[maxi] < a[i])
				maxi = i;
		}
		swap(&a[left], &a[mini]);
		swap(&a[right], &a[maxi]);

		//找到区间的最大和最小值后需要缩小区间
		left++;
		right--;
	}
}



//向下调整(左右子树都是大堆/小堆)
void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child] < a[child + 1])//<:建大堆 >:建小堆
		{
			child++;
		}	

		if (a[parent] < a[child])//<:建大堆 >:建小堆
		{
			swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

//排升序-建大堆    排降序-建小堆 （调整向上、向下调整的比较符号）
void HeapSort(int* a, int n)
{
	//向下调整建堆  时间复杂度：O(N)
	for (int i = (n - 2) / 2; i >= 0; i--)//n-2 => n-1-1 需要减多一次1找到下标位置
	{
		AdjustDown(a, n, i);//从尾数据开始找父节点
	}

	//向下调整  时间复杂度：O(N*logN)
	for (int i = n - 1; i >= 0; i--)
	{
		swap(&a[i], &a[0]);
		AdjustDown(a, i, 0);
	}
}
