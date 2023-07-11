#include"SeqList.h"



void SeqListTest1()
{
	SL s;
	SLInit(&s);

	SLPushBack(&s, 1);
	SLPushBack(&s, 2);
	SLPushBack(&s, 3);
	SLPushBack(&s, 4);
	SLPrint(&s);

	SLPopBack(&s);
	SLPopBack(&s);
	SLPopBack(&s);
	SLPopBack(&s);
	SLPrint(&s);

	//SLPopBack(&s);


	SLDestroy(&s);
}

void SeqListTest2()
{
	SL s;
	SLInit(&s);

	SLPushFront(&s, 1);
	SLPushFront(&s, 2);
	SLPushFront(&s, 3);
	SLPushFront(&s, 4);
	SLPushFront(&s, 5);
	SLPrint(&s);
	SLPopFront(&s);
	SLPopFront(&s);
	SLPopFront(&s);
	SLPrint(&s);

	SLDestroy(&s);
}

void SeqListTest3()
{
	SL s;
	SLInit(&s);
	SLPushFront(&s, 1);
	SLPushFront(&s, 2);
	SLPushFront(&s, 3);
	SLPushFront(&s, 4);
	SLPushFront(&s, 5);
	SLPushFront(&s, 6);
	SLPrint(&s);

	//SLErase(&s, 3);
	//SLPopFront(&s);
	//SLPopFront(&s);
	//SLPrint(&s);

	int ret = SLFind(&s, 5);
	printf("%d ", ret);

	SLDestroy(&s);
}


int main()
{
	SeqListTest3();
	return 0;
}