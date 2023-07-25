#define _CRT_SECURE_NO_WARNINGS 1

//leetcode:225. 用队列实现栈
//typedef struct {
//    Queue q1;
//    Queue q2;
//} MyStack;
//
//
//MyStack* myStackCreate() {
//    MyStack* st = (MyStack*)malloc(sizeof(MyStack));
//    QueueInit(&st->q1);
//    QueueInit(&st->q2);
//    return st;
//}
//
//void myStackPush(MyStack* obj, int x) {
//    if (!QueueEmpty(&obj->q1))
//        QueuePush(&obj->q1, x);
//    else
//        QueuePush(&obj->q2, x);
//}
//
//int myStackPop(MyStack* obj) {
//    Queue* empty = &obj->q1;
//    Queue* nonempty = &obj->q2;
//    if (!QueueEmpty(&obj->q1))
//    {
//        empty = &obj->q2;
//        nonempty = &obj->q1;
//    }
//
//    while (QueueSize(nonempty) > 1)
//    {
//        QueuePush(empty, QueueFront(nonempty));
//        QueuePop(nonempty);
//    }
//    int top = QueueFront(nonempty);
//    QueuePop(nonempty);
//    return top;
//
//}
//
//int myStackTop(MyStack* obj) {
//    if (!QueueEmpty(&obj->q1))
//        return QueueBack(&obj->q1);
//    else
//        return QueueBack(&obj->q2);
//}
//
//bool myStackEmpty(MyStack* obj) {
//    return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
//}
//
//void myStackFree(MyStack* obj) {
//    QueueDestroy(&obj->q1);
//    QueueDestroy(&obj->q2);
//    free(obj);
//}


//leetcode:232. 用栈实现队列
//typedef struct {
//    ST stpush;
//    ST stpop;
//} MyQueue;
//
//
//MyQueue* myQueueCreate() {
//    MyQueue* ptr = (MyQueue*)malloc(sizeof(MyQueue));
//    STInit(&ptr->stpush);
//    STInit(&ptr->stpop);
//    return ptr;
//}
//
//void myQueuePush(MyQueue* obj, int x) {
//    STPush(&obj->stpush, x);
//}
//
//int myQueuePeek(MyQueue* obj) {
//    if (STEmpty(&obj->stpop))
//    {
//        while (STSize(&obj->stpush))
//        {
//            STPush(&obj->stpop, STTop(&obj->stpush));
//            STPop(&obj->stpush);
//        }
//    }
//    return STTop(&obj->stpop);
//}
//
//int myQueuePop(MyQueue* obj) {
//    int top = myQueuePeek(obj);
//    STPop(&obj->stpop);
//    return top;
//}
//
//bool myQueueEmpty(MyQueue* obj) {
//    return STEmpty(&obj->stpush) && STEmpty(&obj->stpop);
//}
//
//void myQueueFree(MyQueue* obj) {
//    STDestroy(&obj->stpush);
//    STDestroy(&obj->stpop);
//    free(obj);
//}


//leetcode:622. 设计循环队列
//typedef struct {
//    int* a;
//    int front;
//    int rear;
//    int k;
//} MyCircularQueue;
//
//
//MyCircularQueue* myCircularQueueCreate(int k) {
//    MyCircularQueue* ptr = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
//    ptr->a = (int*)malloc(sizeof(int) * (k + 1));
//    ptr->front = 0;
//    ptr->rear = 0;
//    ptr->k = k;
//    return ptr;
//}
//
//bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
//    return obj->front == obj->rear;
//}
//
//bool myCircularQueueIsFull(MyCircularQueue* obj) {
//    return ((obj->rear + 1) % (obj->k + 1) == obj->front);
//}
//
//
//bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
//    if (myCircularQueueIsFull(obj))
//        return false;
//
//    obj->a[obj->rear] = value;
//    obj->rear++;
//    obj->rear %= (obj->k + 1);
//    return true;
//}
//
//bool myCircularQueueDeQueue(MyCircularQueue* obj) {
//    if (myCircularQueueIsEmpty(obj))
//        return false;
//
//    obj->front++;
//    obj->front %= (obj->k + 1);
//    return true;
//}
//
//int myCircularQueueFront(MyCircularQueue* obj) {
//    if (myCircularQueueIsEmpty(obj))
//        return -1;
//
//    return obj->a[obj->front];
//}
//
//int myCircularQueueRear(MyCircularQueue* obj) {
//    if (myCircularQueueIsEmpty(obj))
//        return -1;
//
//    int rear = obj->rear;
//    if (rear == 0)
//        rear = obj->k + 1;
//    return obj->a[rear - 1];
//}
//
//
//void myCircularQueueFree(MyCircularQueue* obj) {
//    free(obj->a);
//    free(obj);
//}