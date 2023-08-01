#include"Sort.h"

void SelectSortTest()
{
	int a[] = { 5,1,8,2,4,3,7,9,6 };
	PrintArray(a, sizeof(a) / sizeof(int));
	SelectSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void HeapSortTest()
{
	int a[] = { 5,1,8,2,4,3,7,9,6 };
	PrintArray(a, sizeof(a) / sizeof(int));
	HeapSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

int main()
{
	SelectSortTest();
	HeapSortTest();

	return 0;
}