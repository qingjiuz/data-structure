#include"Stack.h"

//初始化
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
	ps->capacity = 4;//初始化的容量
	ps->top = 0;	//top指栈顶元素的下一个位置
}

//销毁
void STDestroy(ST* ps)
{
	assert(ps);

	free(ps->a);
}

//入栈
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

//出栈
void STPop(ST* ps)
{
	assert(ps);
	assert(!STEmpty(ps));

	ps->top--;
}

//获取栈中有效数据元素个数
int STSize(ST* ps)
{
	assert(ps);

	return ps->top;
}

//检查栈内数据数量是否为空
bool STEmpty(ST* ps)
{
	assert(ps);

	return ps->top == 0;
}

//获取栈顶元素
STDataType STTop(ST* ps)
{
	assert(ps);
	assert(!STEmpty(ps));

	return ps->a[ps->top - 1];
}
