#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType* arr;
	int top;//ջ��
	int capacity;//����
}Stack;

//ջ�ĳ�ʼ��
void STIniti(Stack* pst);
//ѹջ
void STPush(Stack* pst, STDataType x);
//��ջ
void STPop(Stack* pst);
//�п�
bool IsEmpty(Stack* pst);
//��ȡջ��Ԫ�� 
STDataType STTop(Stack* pst);
// ��ȡջ����ЧԪ�ظ��� 
int STSize(Stack* pst);
//����ջ
void STDestroy(Stack* pst);

void STIniti(Stack* pst)
{
	assert(pst);

	pst->arr = NULL;
	pst->capacity = 0;
	//top ָ��ջ�����ݵ���һ��λ��
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
	//�п�
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
	//����peek������popstΪ��ʱ����������
	//��¼ͷ��Ԫ�أ����㷵��
	int front = myQueuePeek(obj);
	STPop(&obj->popst);
	return front;
}

int myQueuePeek(MyQueue* obj) {

	if (IsEmpty(&obj->popst))
	{
		//��pushpst�����ݵ���
		while (!IsEmpty(&obj->pushst))
		{
			STPush(&obj->popst, STTop(&obj->pushst));
			//�ߵ����ɾ��
			STPop(&obj->pushst);
		}
	}
	return STTop(&obj->popst);
}

bool myQueueEmpty(MyQueue* obj) {
	//����ջ��Ϊ�ղ�Ϊ��
	return IsEmpty(&obj->pushst) && IsEmpty(&obj->popst);
}

void myQueueFree(MyQueue* obj) {
	STDestroy(&obj->pushst);
	STDestroy(&obj->popst);
	free(obj);
}