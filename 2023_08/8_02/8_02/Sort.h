#include<stdio.h>
#include<stdlib.h>
#include<time.h>



void Swap(int* a, int* b);
void PrintArray(int* a, int n);

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
