#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>


void Swap(int* a, int* b);
void PrintArray(int* a, int n);

//直接插入排序
void InsertSort(int* a, int n);

//希尔排序
void ShellSort(int* a, int n);

//选择排序
void SelectSort(int* a, int n);

//堆排序
void AdjustDown(int* a, int n, int root);
void HeapSort(int* a, int n);

//冒泡排序
void BubbleSort(int* a, int n);

//快速排序
void QuickSort(int* a, int left, int right);
//Horae版本
void QuickSort1(int* a, int left, int right);
//挖坑法
void QuickSort2(int* a, int left, int right);
//前后指针法
void QuickSort3(int* a, int left, int right);

//快速排序（非递归）
void QuickSortNonR(int* a, int left, int right);

//归并排序
void MergeSort(int* a, int n);

//归并排序（非递归）
void MergeSortNonR(int* a, int n);

//计数排序
void CountSort(int* a, int n);
