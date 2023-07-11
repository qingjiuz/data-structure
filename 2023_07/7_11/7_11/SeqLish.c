#include"SeqList.h"

//����һ��˳���
void SLInit(SL* ps)
{
	assert(ps);

	ps->a = (SLDataType*)malloc(sizeof(SLDataType) * Inception);
	if (ps->a == NULL)
	{
		perror("malloc fail");
		return;
	}

	ps->size = 0;
	ps->capacity = Inception;
}

//����һ��˳���
void SLDestroy(SL* ps)
{
	assert(ps);

	free(ps->a);
	ps->a = NULL;
}

//��ӡ
void SLPrint(SL* ps)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

//�������
void SLChackCapacity(SL* ps)
{
	if (ps->size == ps->capacity)
	{
		SLDataType* ptr = (SLDataType*)realloc(ps->a, sizeof(SLDataType) * ps->capacity * 2);
		if (ptr == NULL)
		{
			perror("realloc fail");
			return;
		}

		ps->a = ptr;
		ps->capacity *= 2;
	}

}

//β��
void SLPushBack(SL* ps, SLDataType x)
{
	assert(ps);

	SLChackCapacity(ps);
	ps->a[ps->size++] = x;
}

//βɾ
void SLPopBack(SL* ps)
{
	assert(ps);
	assert(ps->size > 0);

	ps->size--;
}

//ǰ��
void SLPushFront(SL* ps, SLDataType x)
{
	//assert(ps);

	//SLChackCapacity(ps);

	//int end = ps->size;
	//while (end)
	//{
	//	ps->a[end] = ps->a[end - 1];
	//	end--;
	//}
	//ps->a[0] = x;
	//ps->size++;

	SLInsert(ps, 0, x);
}

//ǰɾ
void SLPopFront(SL* ps)
{
	//assert(ps);
	//assert(ps->size > 0);

	//int begin = 1;
	//while (begin < ps->size)
	//{
	//	ps->a[begin - 1] = ps->a[begin];
	//	begin++;
	//}
	//ps->size--;

	SLErase(ps, 0);
}

//�м����
void SLInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);

	SLChackCapacity(ps);

	int end = ps->size;
	while (end >= pos)
	{
		ps->a[end] = ps->a[end - 1];
		end--;
	}
	ps->a[pos] = x;
	ps->size++;

}

//�м�ɾ��
void SLErase(SL* ps, int pos)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);

	int begin = pos + 1;
	while (begin < ps->size)
	{
		ps->a[begin - 1] = ps->a[begin];
		begin++;
	}
	ps->size--;

}

//����
int SLFind(SL* ps, SLDataType x)
{
	assert(ps);

	for (int i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}
	return -1;
}
