#include"Sort.h"
#include"Stack.h"

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//直接插入排序
void InserSort(int* a, int n)
{
	for (int i = 1; i < n; i++)
	{
		int end = i - 1;
		int tmp = a[i];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

//冒泡排序
void BubbleSort(int* a, int n)
{
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n - j - 1; i++)
		{
			int left = i, right = i + 1;
			if (a[left] > a[right])
			{
				Swap(&a[left], &a[right]);
			}
		}
	}
}

int GetMidNumi(int* a, int left, int right)
{
	int mid = (right - left) / 2;
	if (a[left] > a[right])
	{
		if (a[left] < a[mid])
			return left;
		else if (a[right] > a[mid])
			return right;
		else
			return mid;
	}
	else //a[right] > a[left]
	{
		if (a[right] < a[mid])
			return right;
		else if (a[left] > a[mid])
			return left;
		else
			return mid;
	}
}

//快速排序
////Horae版本
//void QuickSort1(int* a, int left, int right)
//{
//	if (left >= right)
//		return;
//
//	int begin = left, end = right;
//
//	//随机keyi值
//	//int randi = left + (rand() % (right - left));
//	//Swap(&a[randi], &a[left]);
//
//	//三数取中
//	int midi = GetMidNumi(a, left, right);
//	if(midi != left)
//		Swap(&a[midi], &a[left]);
//	
//	int keyi = left;
//	while (left < right)
//	{
//		//右边找小
//		while (right > left && a[right] >= a[keyi])
//			right--;
//
//		//左边找大
//		while (right > left && a[left] <= a[keyi])
//			left++;
//
//		Swap(&a[left], &a[right]);
//	}
//	Swap(&a[left], &a[keyi]);	//keyi位置的值与left位置的值发生交换
//	keyi = left;				//keyi需要找到交换后的位置，即left
//
//	//[begin keyi-1] keyi [keyi+1 end]
//	QuickSort1(a, begin, keyi - 1);
//	QuickSort1(a, keyi + 1, end);
//}
//
////挖坑法
//void QuickSort2(int* a, int left, int right)
//{
//	if (left >= right)
//		return;
//
//	int begin = left, end = right;
//	//三数取中
//	int midi = GetMidNumi(a, left, right);
//	if (midi != left)
//		Swap(&a[midi], &a[left]);
//
//	int hole = left;
//	int key = a[left];
//
//	while (left < right)
//	{
//		//右边找小
//		while (left < right && a[right] >= key)
//			right--;
//		a[hole] = a[right];
//		hole = right;
//
//		//左边找大
//		while (left < right && a[left] <= key)
//			left++;
//		a[hole] = a[left];
//		hole = left;
//	}
//	a[hole] = key;
//
//	//[begin hole-1] hole [hole+1 end]
//	QuickSort2(a, begin, hole - 1);
//	QuickSort2(a, hole + 1, end);
//}
//
////前后指针法
//void QuickSort3(int* a, int left, int right)
//{
//	if (left >= right)
//		return;
//
//	int begin = left, end = right;
//	//三数取中
//	int midi = GetMidNumi(a, left, right);
//	if (midi != left)
//		Swap(&a[midi], &a[left]);
//
//	int prev = left;
//	int cur = left + 1;
//
//	int keyi = left;
//	while (cur <= right)
//	{
//		if (a[cur] < a[keyi] && ++prev != cur)
//		{
//			Swap(&a[cur], &a[prev]);
//		}
//		cur++;
//	}
//	Swap(&a[prev], &a[keyi]);	//keyi位置的值与prev位置的值发生交换
//	keyi = prev;				//keyi需要找到交换后的位置，即prev
//
//	//[begin keyi-1] keyi [keyi+1 end]
//	QuickSort3(a, begin, keyi - 1);
//	QuickSort3(a, keyi + 1, end);
//}


//Horae版本
int PartSort1(int* a, int left, int right)
{
	int begin = left, end = right;

	//三数取中
	int midi = GetMidNumi(a, left, right);
	if (midi != left)
		Swap(&a[midi], &a[left]);

	int keyi = left;
	while (left < right)
	{
		//右边找小
		while (right > left && a[right] >= a[keyi])
			right--;

		//左边找大
		while (right > left && a[left] <= a[keyi])
			left++;

		Swap(&a[left], &a[right]);
	}
	Swap(&a[left], &a[keyi]);	//keyi位置的值与left位置的值发生交换
	keyi = left;				//keyi需要找到交换后的位置，即left
	return keyi;
}

//挖坑法
int PartSort2(int* a, int left, int right)
{
	int begin = left, end = right;
	//三数取中
	int midi = GetMidNumi(a, left, right);
	if (midi != left)
		Swap(&a[midi], &a[left]);

	int hole = left;
	int key = a[left];

	while (left < right)
	{
		//右边找小
		while (left < right && a[right] >= key)
			right--;
		a[hole] = a[right];
		hole = right;

		//左边找大
		while (left < right && a[left] <= key)
			left++;
		a[hole] = a[left];
		hole = left;
	}
	a[hole] = key;

	return hole;
}

//前后指针法
int PartSort3(int* a, int left, int right)
{
	int begin = left, end = right;
	//三数取中
	int midi = GetMidNumi(a, left, right);
	if (midi != left)
		Swap(&a[midi], &a[left]);

	int prev = left;
	int cur = left + 1;

	int keyi = left;
	while (cur <= right)
	{
		if (a[cur] < a[keyi] && ++prev != cur)
		{
			Swap(&a[cur], &a[prev]);
		}
		cur++;
	}
	Swap(&a[prev], &a[keyi]);	//keyi位置的值与prev位置的值发生交换
	keyi = prev;				//keyi需要找到交换后的位置，即prev

	return keyi;
}

//void QuickSort(int* a, int left, int right)
//{
//	if (left >= right)
//		return;
//
//	int keyi = PartSort3(a, left, right);
//	QuickSort(a, left, keyi - 1);
//	QuickSort(a, keyi + 1, right);
//}

//优化版本
void QuickSort(int* a, int left, int right)
{
	if (left >= right)
		return;

	//小区间优化（当区间数据量较小时，区间的数据接近有序，可以选择用插入排序代替）
	if ((right - left + 1) > 10)
	{
		int keyi = PartSort3(a, left, right);
		QuickSort(a, left, keyi - 1);
		QuickSort(a, keyi + 1, right);
	}
	else
	{
		InserSort(a + left, right - left + 1);
	}
}

//快速排序（非递归）
void QuickSortNonR(int* a, int left, int right)
{
	ST st;
	STInit(&st);
	STPush(&st, right);
	STPush(&st, left);

	while (!STEmpty(&st))
	{
		int begin = STTop(&st);
		STPop(&st);
		int end = STTop(&st);
		STPop(&st);

		int keyi = PartSort3(a, begin, end);
		if (end > keyi + 1)
		{
			STPush(&st, end);
			STPush(&st, keyi + 1);
		}

		if (begin < keyi - 1)
		{
			STPush(&st, keyi - 1);
			STPush(&st, begin);
		}
	}

	STDestroy(&st);
}
