#include "SList.h"

void SLtest1()
{
	SListNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPushBack(&plist, 5);

	SListPrint(plist);

	//SListPushFront(&plist);
	//SListPushFront(&plist);
	//SListPushFront(&plist);
	//SListPushFront(&plist);
	//SListPushFront(&plist);


	SListPrint(plist);
}

void SLtest2()
{
	SListNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPushBack(&plist, 5);

	SListPrint(plist);

	//SListNode* ptr =  SListFind(plist, 6);
	//检验是否存在所查找的数据
	//if (ptr != NULL)
	//{
	//	SListInsertAfter(ptr, 30);
	//}
	//else
	//{
	//	printf("not find\n");
	//}

	SListNode* ptr = SListFind(plist, 6);
	//检验是否存在所查找的数据
	if (ptr != NULL)
	{
		SListEraseAfter(ptr);
	}
	else
	{
		printf("not find\n");
	}

	SListPrint(plist);

	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPopFront(&plist);

	SListPrint(plist);

}

void SLtest3()
{
	SListNode* plist = NULL;
	//SListPushBack(&plist, 1);
	//SListPushBack(&plist, 2);
	//SListPushBack(&plist, 3);
	//SListPushBack(&plist, 4);
	//SListPushBack(&plist, 5);

	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);
	SListPushFront(&plist, 5);

	SListPrint(plist);

	SListDestroy(plist);
	plist = NULL;
}

int main()
{
	SLtest3();
	return 0;
}