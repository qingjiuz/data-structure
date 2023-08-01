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
	//	swap(&a[mini], &a[left]);
	//}

	//�Ż��汾

	//for (int j = 0; j < n; j++)//����������ɻ����ѭ�������
	//{
	//	//ÿ��ѭ������Сһ������
	//	int mini = j, maxi = n - j - 1;
	//	int left = mini, right = maxi;

	int left = 0, right = n - 1;
	while(left < right)
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
		swap(&a[left], &a[mini]);
		swap(&a[right], &a[maxi]);

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
		swap(&a[i], &a[0]);
		AdjustDown(a, i, 0);
	}
}
