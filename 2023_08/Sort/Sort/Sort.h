#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>


void Swap(int* a, int* b);
void PrintArray(int* a, int n);

//ֱ�Ӳ�������
void InsertSort(int* a, int n);

//ϣ������
void ShellSort(int* a, int n);

//ѡ������
void SelectSort(int* a, int n);

//������
void AdjustDown(int* a, int n, int root);
void HeapSort(int* a, int n);

//ð������
void BubbleSort(int* a, int n);

//��������
void QuickSort(int* a, int left, int right);
//Horae�汾
void QuickSort1(int* a, int left, int right);
//�ڿӷ�
void QuickSort2(int* a, int left, int right);
//ǰ��ָ�뷨
void QuickSort3(int* a, int left, int right);

//�������򣨷ǵݹ飩
void QuickSortNonR(int* a, int left, int right);

//�鲢����
void MergeSort(int* a, int n);

//�鲢���򣨷ǵݹ飩
void MergeSortNonR(int* a, int n);

//��������
void CountSort(int* a, int n);
