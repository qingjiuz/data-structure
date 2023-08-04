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

//ֱ�Ӳ�������
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

//ϣ������
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

//ѡ������
void SelectSort(int* a, int n)
{
	//for (int j = 0; j < n; j++)
	//{
	//	int left = j;
	//	int mini = j;

	//	//����Сֵ����left����
	//	for (int i = j + 1; i < n; i++)
	//	{
	//		if (a[mini] > a[i])
	//		{
	//			mini = i;
	//		}
	//	}
	//	Swap(&a[mini], &a[left]);
	//}

	//�Ż��汾

	//for (int j = 0; j < n; j++)//����������ɻ����ѭ�������
	//{
	//	//ÿ��ѭ������Сһ������
	//	int mini = j, maxi = n - j - 1;
	//	int left = mini, right = maxi;

	int left = 0, right = n - 1;
	while (left < right)
	{
		int mini = left, maxi = right;//����
		for (int i = 1 + left; i <= right; i++)
		{
			//����С
			if (a[mini] > a[i])
				mini = i;

			//�����
			if (a[maxi] < a[i])
				maxi = i;
		}
		Swap(&a[left], &a[mini]);
		Swap(&a[right], &a[maxi]);

		//�ҵ������������Сֵ����Ҫ��С����
		left++;
		right--;
	}
}

//���µ���(�����������Ǵ��/С��)
void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child] < a[child + 1])//<:����� >:��С��
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

//������
//������-�����    �Ž���-��С�� ���������ϡ����µ����ıȽϷ��ţ�
void HeapSort(int* a, int n)
{
	//���µ�������  ʱ�临�Ӷȣ�O(N)
	for (int i = (n - 2) / 2; i >= 0; i--)//n-2 => n-1-1 ��Ҫ����һ��1�ҵ��±�λ��
	{
		AdjustDown(a, n, i);//��β���ݿ�ʼ�Ҹ��ڵ�
	}

	//���µ���  ʱ�临�Ӷȣ�O(N*logN)
	for (int i = n - 1; i >= 0; i--)
	{
		Swap(&a[i], &a[0]);
		AdjustDown(a, i, 0);
	}
}

//ֱ�Ӳ�������
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

//ð������
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

//��������
//Horae�汾
void QuickSort1(int* a, int left, int right)
{
	if (left >= right)
		return;

	int begin = left, end = right;

	//���keyiֵ
	//int randi = left + (rand() % (right - left));
	//Swap(&a[randi], &a[left]);

	//����ȡ��
	int midi = GetMidNumi(a, left, right);
	if(midi != left)
		Swap(&a[midi], &a[left]);
	
	int keyi = left;
	while (left < right)
	{
		//�ұ���С
		while (right > left && a[right] >= a[keyi])
			right--;

		//����Ҵ�
		while (right > left && a[left] <= a[keyi])
			left++;

		Swap(&a[left], &a[right]);
	}
	Swap(&a[left], &a[keyi]);	//keyiλ�õ�ֵ��leftλ�õ�ֵ��������
	keyi = left;				//keyi��Ҫ�ҵ��������λ�ã���left

	//[begin keyi-1] keyi [keyi+1 end]
	QuickSort1(a, begin, keyi - 1);
	QuickSort1(a, keyi + 1, end);
}

//�ڿӷ�
void QuickSort2(int* a, int left, int right)
{
	if (left >= right)
		return;

	int begin = left, end = right;
	//����ȡ��
	int midi = GetMidNumi(a, left, right);
	if (midi != left)
		Swap(&a[midi], &a[left]);

	int hole = left;
	int key = a[left];

	while (left < right)
	{
		//�ұ���С
		while (left < right && a[right] >= key)
			right--;
		a[hole] = a[right];
		hole = right;

		//����Ҵ�
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

//ǰ��ָ�뷨
void QuickSort3(int* a, int left, int right)
{
	if (left >= right)
		return;

	int begin = left, end = right;
	//����ȡ��
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
	Swap(&a[prev], &a[keyi]);	//keyiλ�õ�ֵ��prevλ�õ�ֵ��������
	keyi = prev;				//keyi��Ҫ�ҵ��������λ�ã���prev

	//[begin keyi-1] keyi [keyi+1 end]
	QuickSort3(a, begin, keyi - 1);
	QuickSort3(a, keyi + 1, end);
}


//Horae�汾
int PartSort1(int* a, int left, int right)
{
	int begin = left, end = right;

	//����ȡ��
	int midi = GetMidNumi(a, left, right);
	if (midi != left)
		Swap(&a[midi], &a[left]);

	int keyi = left;
	while (left < right)
	{
		//�ұ���С
		while (right > left && a[right] >= a[keyi])
			right--;

		//����Ҵ�
		while (right > left && a[left] <= a[keyi])
			left++;

		Swap(&a[left], &a[right]);
	}
	Swap(&a[left], &a[keyi]);	//keyiλ�õ�ֵ��leftλ�õ�ֵ��������
	keyi = left;				//keyi��Ҫ�ҵ��������λ�ã���left
	return keyi;
}

//�ڿӷ�
int PartSort2(int* a, int left, int right)
{
	int begin = left, end = right;
	//����ȡ��
	int midi = GetMidNumi(a, left, right);
	if (midi != left)
		Swap(&a[midi], &a[left]);

	int hole = left;
	int key = a[left];

	while (left < right)
	{
		//�ұ���С
		while (left < right && a[right] >= key)
			right--;
		a[hole] = a[right];
		hole = right;

		//����Ҵ�
		while (left < right && a[left] <= key)
			left++;
		a[hole] = a[left];
		hole = left;
	}
	a[hole] = key;

	return hole;
}

//ǰ��ָ�뷨
int PartSort3(int* a, int left, int right)
{
	int begin = left, end = right;
	//����ȡ��
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
	Swap(&a[prev], &a[keyi]);	//keyiλ�õ�ֵ��prevλ�õ�ֵ��������
	keyi = prev;				//keyi��Ҫ�ҵ��������λ�ã���prev

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

//�Ż��汾
void QuickSort(int* a, int left, int right)
{
	if (left >= right)
		return;

	//С�����Ż�����������������Сʱ����������ݽӽ����򣬿���ѡ���ò���������棩
	if ((right - left + 1) > 10)
	{
		//����keyiλ���Ե�������
		int keyi = PartSort3(a, left, right);
		QuickSort(a, left, keyi - 1);
		QuickSort(a, keyi + 1, right);
	}
	else
	{
		InserSort(a + left, right - left + 1);
	}
}

//�������򣨷ǵݹ飩
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
	
	//������ݹ�-->�����������ݹ飬������������ݷֱ�����
	int mid = (right + left) / 2;
	_MergeSort(a, tmp, left, mid);
	_MergeSort(a, tmp, mid + 1, right);

	//�ϲ�
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

	memcpy(a + left, tmp + left, sizeof(int) * (right - left + 1));//������+1�ŵ�������
}

//�鲢����
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail");
		return;
	}

	//��Ҫ׼ȷ��������
	_MergeSort(a, tmp, 0, n - 1);

	free(tmp);
}

//�鲢���򣨷ǵݹ飩
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

			//1.�ڴ�ѭ����һ�θ��Ǻϲ��õ�����-->��������
			//if (end1 >= n)
			//{
			//	end1 = n - 1;
			//	//���ұߵ����򲻴���
			//	begin2 = n;
			//	end2 = n - 1;
			//}
			//else if (begin2 >= n)
			//{
			//	//���ұߵ����򲻴���
			//	begin2 = n;
			//	end2 = n - 1;
			//}
			//else if (end2 >= n)
			//{
			//	end2 = n - 1;
			//}

			//2.�ڴ�ѭ���ڸ�������õ�����-->��������
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

//��������
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
	//��Բ��
	int range = max - min + 1;//��������Ҫ+1

	int* Count = (int*)malloc(sizeof(int) * range);
	if (Count == NULL)
	{
		perror("malloc fail");
		return;
	}
	//��ʼ��
	memset(Count, 0, sizeof(int) * range);

	//����
	for (int i = 0; i < n; i++)
	{
		Count[a[i] - min]++;
	}

	//����
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
