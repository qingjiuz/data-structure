#include"Stack.h"

//��ʼ��
void STInit(ST* ps)
{
	assert(ps);

	ST* phead = (ST*)malloc(sizeof(ST) * 4);
	if (phead == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	ps->a = phead;
	ps->capacity = 4;//��ʼ��������
	ps->top = 0;	//topָջ��Ԫ�ص���һ��λ��
}

//����
void STDestroy(ST* ps)
{
	assert(ps);

	free(ps->a);
}

//��ջ
void STPush(ST* ps, STDataType x)
{
	assert(ps);

	if (ps->capacity == ps->top)
	{
		ST* phead = (ST*)realloc(ps->a, sizeof(ST) * ps->capacity * 2);
		if (phead == NULL)
		{
			perror("realloc fail");
			exit(-1);
		}
		ps->a = phead;
		ps->capacity *= 2;
	}

	ps->a[ps->top] = x;
	ps->top++;
}

//��ջ
void STPop(ST* ps)
{
	assert(ps);
	assert(!STEmpty(ps));

	ps->top--;
}

//��ȡջ����Ч����Ԫ�ظ���
int STSize(ST* ps)
{
	assert(ps);

	return ps->top;
}

//���ջ�����������Ƿ�Ϊ��
bool STEmpty(ST* ps)
{
	assert(ps);

	return ps->top == 0;
}

//��ȡջ��Ԫ��
STDataType STTop(ST* ps)
{
	assert(ps);
	assert(!STEmpty(ps));

	return ps->a[ps->top - 1];
}
