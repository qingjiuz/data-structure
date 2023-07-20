#include"List.h"

void ListTest1()
{
	ListNode* plist = LTInit();

	LTPushBack(plist, 1);
	LTPushBack(plist, 2);
	LTPushBack(plist, 3);
	LTPushBack(plist, 4);
	LTPushBack(plist, 5);
	LTPrint(plist);

	//LTPopBack(plist);
	//LTPopBack(plist);
	//LTPopBack(plist);
	//LTPopBack(plist);

	ListNode* tmp = LTFind(plist, 3);
	LTInsert(tmp, 30);

	LTPrint(plist);

	LTDestory(plist);
	free(plist);
	plist = NULL;
}

void ListTest2()
{
	ListNode* plist = LTInit();

	LTPushFront(plist, 1);
	LTPushFront(plist, 2);
	LTPushFront(plist, 3);
	LTPushFront(plist, 4);
	LTPushFront(plist, 5);
	LTPrint(plist);

	//LTPopFront(plist);
	//LTPopFront(plist);
	//LTPopFront(plist);
	//LTPopFront(plist);

	ListNode* tmp = LTFind(plist, 3);
	LTInsert(tmp, 30);

	LTPrint(plist);

	//LTDestory(plist);
	//free(plist);
	//plist = NULL;
}

void ListTest3()
{
	ListNode* plist = LTInit();

	LTPushBack(plist, 1);
	LTPushBack(plist, 2);
	LTPushBack(plist, 3);
	LTPushBack(plist, 4);
	LTPushBack(plist, 5);
	LTPushBack(plist, 6);
	LTPrint(plist);

	LTPushFront(plist, 7);
	LTPushFront(plist, 8);
	LTPushFront(plist, 9);
	LTPrint(plist);

	//LTPopBack(plist);
	//LTPopBack(plist);
	//LTPopBack(plist);
	//LTPrint(plist);

	//LTPopFront(plist);
	//LTPopFront(plist);
	//LTPopFront(plist);
	//LTPrint(plist);

	LTDestory(plist);
	//free(plist);
	//plist = NULL;

}

int main()
{
	ListTest3();

	return 0;
}