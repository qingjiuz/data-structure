#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define Inception 5

typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* a;
	int size;
	int capacity;
}SL;

//�������ܣ���ɾ���

//����һ��˳���
void SLInit(SL* ps);
//����һ��˳���
void SLDestroy(SL* ps);

//��ӡ˳���
void SLPrint(SL* ps);

//�������
void SLChackCapacity(SL* ps);

//β��/βɾ
void SLPushBack(SL* ps, SLDataType x);
void SLPopBack(SL* ps);

//ǰɾ/ǰ��
void SLPushFront(SL* ps, SLDataType x);
void SLPopFront(SL* ps);

//�м����/ɾ��
void SLInsert(SL* ps, int pos, SLDataType x);
void SLErase(SL* ps, int pos);

//����
int SLFind(SL* ps, SLDataType x);