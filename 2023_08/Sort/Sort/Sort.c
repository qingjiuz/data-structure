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

//希尔排序
void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 0)
	{
		gap /= 2;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[i + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
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
	//	Swap(&a[mini], &a[left]);
	//}

	//优化版本

	//for (int j = 0; j < n; j++)//排序完后依旧会存在循环的情况
	//{
	//	//每次循环都缩小一次区间
	//	int mini = j, maxi = n - j - 1;
	//	int left = mini, right = maxi;

	int left = 0, right = n - 1;
	while (left < right)
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
		Swap(&a[left], &a[mini]);
		Swap(&a[right], &a[maxi]);

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

//堆排序
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
		Swap(&a[i], &a[0]);
		AdjustDown(a, i, 0);
	}
}

//直接插入排序
void InsertSort(int* a, int n)
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
//Horae版本
void QuickSort1(int* a, int left, int right)
{
	if (left >= right)
		return;

	int begin = left, end = right;

	//随机keyi值
	//int randi = left + (rand() % (right - left));
	//Swap(&a[randi], &a[left]);

	//三数取中
	int midi = GetMidNumi(a, left, right);
	if(midi != left)
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

	//[begin keyi-1] keyi [keyi+1 end]
	QuickSort1(a, begin, keyi - 1);
	QuickSort1(a, keyi + 1, end);
}

//挖坑法
void QuickSort2(int* a, int left, int right)
{
	if (left >= right)
		return;

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

	//[begin hole-1] hole [hole+1 end]
	QuickSort2(a, begin, hole - 1);
	QuickSort2(a, hole + 1, end);
}

//前后指针法
void QuickSort3(int* a, int left, int right)
{
	if (left >= right)
		return;

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

	//[begin keyi-1] keyi [keyi+1 end]
	QuickSort3(a, begin, keyi - 1);
	QuickSort3(a, keyi + 1, end);
}


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
		//返回keyi位置以调整区间
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


void _MergeSort(int* a, int* tmp, int left, int right)
{
	if (left >= right)
		return;
	
	//子区间递归-->当走完两个递归，即两区间的数据分别有序
	int mid = (right + left) / 2;
	_MergeSort(a, tmp, left, mid);
	_MergeSort(a, tmp, mid + 1, right);

	//合并
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int i = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[i] = a[begin1++];
		}
		else
		{
			tmp[i] = a[begin2++];
		}
		i++;
	}

	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}

	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}

	memcpy(a + left, tmp + left, sizeof(int) * (right - left + 1));//闭区间+1才等于总数
}

//归并排序
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail");
		return;
	}

	//需要准确控制区间
	_MergeSort(a, tmp, 0, n - 1);

	free(tmp);
}

//归并排序（非递归）
void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail");
		return;
	}

	int gap = 1;
	while (gap < n)
	{
		for (int i = 0; i < n; i += gap * 2)
		{
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
			int j = i;

			//1.在此循环外一次覆盖合并好的数组-->修正区域
			//if (end1 >= n)
			//{
			//	end1 = n - 1;
			//	//即右边的区域不存在
			//	begin2 = n;
			//	end2 = n - 1;
			//}
			//else if (begin2 >= n)
			//{
			//	//即右边的区域不存在
			//	begin2 = n;
			//	end2 = n - 1;
			//}
			//else if (end2 >= n)
			//{
			//	end2 = n - 1;
			//}

			//2.在此循环内覆盖排序好的数组-->修正区域
			if (end1 >= n || begin2 >= n)
				break;
			else if (end2 >= n)
				end2 = n - 1;

			//printf("[%d,%d][%d,%d] ", begin1, end1, begin2, end2);

			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					tmp[j] = a[begin1++];
				}
				else
				{
					tmp[j] = a[begin2++];
				}
				j++;
			}

			while (begin1 <= end1)
			{
				tmp[j++] = a[begin1++];
			}

			while (begin2 <= end2)
			{
				tmp[j++] = a[begin2++];
			}
			//2.
			memcpy(a+i, tmp+i, sizeof(int) * (end2 - i + 1));
		}
		//printf("\n");
		//1.
		//memcpy(a, tmp, sizeof(int) * n);
		gap *= 2;
	}
	
	free(tmp);
}

//计数排序
void CountSort(int* a, int n)
{
	int min = a[0], max = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] > max)
			max = a[i];
		
		if (a[i] < min)
			min = a[i];
	}
	//相对差距
	int range = max - min + 1;//闭区间需要+1

	int* Count = (int*)malloc(sizeof(int) * range);
	if (Count == NULL)
	{
		perror("malloc fail");
		return;
	}
	//初始化
	memset(Count, 0, sizeof(int) * range);

	//计数
	for (int i = 0; i < n; i++)
	{
		Count[a[i] - min]++;
	}

	//排序
	int j = 0;
	for (int i = 0; i < range; i++)
	{
		while (Count[i]--)
		{
			a[j++] = i + min;
		}
	}

	free(Count);
}
