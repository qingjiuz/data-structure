#include<stdio.h>

//leetcode:189. ÂÖ×ªÊý×é
//void revesrse(int* nums, int sz)
//{
//	int left = 0;
//	int right = sz-1;
//
//	while(left < right)
//	{
//		int ret = nums[left];
//		nums[left] = nums[right];
//		nums[right] = ret;
//		left++;
//		right--;
//	}
//}
//
//void rotate(int* nums, int numsSize, int k) {
//	if (k > numsSize)
//	{
//		k %= numsSize;
//	}
//
//	reverse(nums, numsSize);
//	reverse(nums, k);
//	reverse((nums+k), (numsSize-k));
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7 };
//	int k = 3;
//	int ns = sizeof(arr) / sizeof(int);
//
//	for (int i = 0; i < ns; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//
//	rotate(arr, ns, k);
//
//	for (int i = 0; i < ns; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}


int missingNumber(int* nums, int numsSize) {
	
	int ret = 0;
	for (int i = 0; i < numsSize; i++)
	{
		ret ^= nums[i];
	}

	for (int i = 0; i < numsSize + 1; i++)
	{
		ret ^= i;
	}

	return ret;
}

int main()
{
	int arr[] = { 1,3,4,0 };
	int sz = sizeof(arr) / sizeof(int);

	int num = missingNumber(arr, sz);
	printf("%d ", num);

	return 0;
}