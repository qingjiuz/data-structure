#include"Sort.h"

int main()
{
	int a[] = { 2,3,1,5,8,7,6,9,4,0 };
	InserSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));

	int b[] = { 2,3,1,5,8,7,6,9,4,0 };
	ShellSort(b, sizeof(b) / sizeof(int));
	PrintArray(b, sizeof(b) / sizeof(int));

	return 0;
}