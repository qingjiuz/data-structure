#include"Sort.h"
#include"Stack.h"

void BubbleSortTest()
{
	int a[] = { 5,3,6,8,1,9,2,4,7 };
	PrintArray(a, sizeof(a) / sizeof(int));
	BubbleSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

//void QuickSort1Test()
//{
//	int a[] = { 5,3,6,8,1,9,2,4,7 };
//	PrintArray(a, sizeof(a) / sizeof(int));
//	QuickSort1(a, 0, sizeof(a) / sizeof(int) - 1);
//	PrintArray(a, sizeof(a) / sizeof(int));
//}
//
//void QuickSort2Test()
//{
//	int a[] = { 5,3,6,8,1,9,2,4,7 };
//	PrintArray(a, sizeof(a) / sizeof(int));
//	QuickSort2(a, 0, sizeof(a) / sizeof(int) - 1);
//	PrintArray(a, sizeof(a) / sizeof(int));
//}
//
//void QuickSort3Test()
//{
//	int a[] = { 5,3,6,8,1,9,2,4,7 };
//	PrintArray(a, sizeof(a) / sizeof(int));
//	QuickSort3(a, 0, sizeof(a) / sizeof(int) - 1);
//	PrintArray(a, sizeof(a) / sizeof(int));
//}

void QuickSortTest()
{
	int a[] = { 5,3,6,8,3,3,2,4,7 };
	PrintArray(a, sizeof(a) / sizeof(int));
	QuickSort(a, 0, sizeof(a) / sizeof(int) - 1);
	PrintArray(a, sizeof(a) / sizeof(int));
}

void QuickSortNonRTest()
{
	int a[] = { 5,3,6,8,3,1,2,4,7 };
	PrintArray(a, sizeof(a) / sizeof(int));
	QuickSortNonR(a, 0, sizeof(a) / sizeof(int) - 1);
	PrintArray(a, sizeof(a) / sizeof(int));
}


int main()
{
	srand(time(NULL));

	BubbleSortTest();
	//QuickSort1Test();
	//QuickSort2Test();
	//QuickSort3Test();
	//QuickSortTest();

	QuickSortNonRTest();

	return 0;
}