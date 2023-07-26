#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int HeapDataType;

typedef struct Heap
{
	HeapDataType* a;
	int size;
	int capacity;
}HP;

void HeapInit(HP* php);
void HeapDsetroy(HP* php);

void AdjustUp(HeapDataType* a, int child);
void HeapPush(HP* php, HeapDataType x);

void AdjustDown(HeapDataType* a, int size,int parent);
void HeapPop(HP* php);

bool HeapEmpty(HP* php);
HeapDataType HeapTop(HP* php);
int HeapSize(HP* php);
void Swap(HeapDataType* p1, HeapDataType* p2);