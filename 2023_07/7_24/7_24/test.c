#include"Queue.h"

void test1()
{
	Queue q;
	QueueInit(&q);

	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);

	printf("%d ", QueueBack(&q));
	printf("%d ", QueueFront(&q));

	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);
	printf("%d ", QueueFront(&q));

	QueueDestroy(&q);
}

int main()
{
	test1();

	return 0;
}