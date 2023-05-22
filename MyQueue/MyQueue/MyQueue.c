#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType* arr;
	int top;//栈顶
	int capacity;//容量
}Stack;

//栈的初始化
void STIniti(Stack* pst);
//压栈
void STPush(Stack* pst, STDataType x);
//出栈
void STPop(Stack* pst);
//判空
bool IsEmpty(Stack* pst);
//获取栈顶元素 
STDataType STTop(Stack* pst);
// 获取栈中有效元素个数 
int STSize(Stack* pst);
//销毁栈
void STDestroy(Stack* pst);

void STIniti(Stack* pst)
{
	assert(pst);

	pst->arr = NULL;
	pst->capacity = 0;
	//top 指向栈顶数据的下一个位置
	pst->top = 0;
}

void STPush(Stack* pst, STDataType x)
{
	assert(pst);

	if (pst->capacity == pst->top)
	{
		//(pst->capacity == 0) ? (pst->capacity = 4) : (pst->capacity *= 2);
		int newcapacity = pst->capacity == 0 ? pst->capacity = 4 : pst->capacity * 2;
		STDataType* tmp = (STDataType*)realloc(pst->arr, 4 * sizeof(STDataType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		pst->arr = tmp;
		pst->capacity = newcapacity;
	}

	pst->arr[pst->top++] = x;
}

bool IsEmpty(Stack* pst)
{
	assert(pst);

	return pst->top == 0;
}

void STPop(Stack* pst)
{
	assert(pst);
	//判空
	assert(!IsEmpty(pst));

	pst->top--;
}

STDataType STTop(Stack* pst)
{
	assert(pst);
	assert(!IsEmpty(pst));

	return pst->arr[pst->top - 1];
}

int STSize(Stack* pst)
{
	assert(pst);

	return pst->top;
}

void STDestroy(Stack* pst)
{
	assert(pst);

	pst->capacity = 0;
	pst->top = 0;
	free(pst->arr);
}

typedef struct {
	Stack pushst;
	Stack popst;
} MyQueue;


MyQueue* myQueueCreate() {
	MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
	if (obj == NULL)
	{
		perror("malloc fail");
		return NULL;
	}

	STIniti(&obj->pushst);
	STIniti(&obj->popst);

	return obj;
}

void myQueuePush(MyQueue* obj, int x) {

	STPush(&obj->pushst, x);
}

int myQueuePop(MyQueue* obj) {
	//调用peek函数，popst为空时，则导入数据
	//记录头部元素，方便返回
	int front = myQueuePeek(obj);
	STPop(&obj->popst);
	return front;
}

int myQueuePeek(MyQueue* obj) {

	if (IsEmpty(&obj->popst))
	{
		//将pushpst的数据导入
		while (!IsEmpty(&obj->pushst))
		{
			STPush(&obj->popst, STTop(&obj->pushst));
			//边导入边删除
			STPop(&obj->pushst);
		}
	}
	return STTop(&obj->popst);
}

bool myQueueEmpty(MyQueue* obj) {
	//两个栈都为空才为空
	return IsEmpty(&obj->pushst) && IsEmpty(&obj->popst);
}

void myQueueFree(MyQueue* obj) {
	STDestroy(&obj->pushst);
	STDestroy(&obj->popst);
	free(obj);
}