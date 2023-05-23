#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int QDataType;
typedef struct QueueNode
{
	QDataType data;
	struct QueueNode* next;
}QNode;

typedef struct Queue
{
	QNode* front;
	QNode* rear;
	int size;//记录数据个数
}Queue;

//初始化队列 
void QueueInit(Queue* pq);
//队尾入队（尾插）
void QueuePush(Queue* pq, QDataType x);
//队头出队（头删）
void QueuePop(Queue* pq);
//获取队列头部元素 
QDataType QueueFront(Queue* pq);
//获取队列队尾元素 
QDataType QueueBack(Queue* pq);
//获取队列中有效元素个数 
int QueueSize(Queue* pq);
//判断链表是否为空
bool IsEmpty(Queue* pq);
//销毁队列 
void QueueDestroy(Queue* pq);

void QueueInit(Queue* pq)
{
	assert(pq);

	pq->front = pq->rear = NULL;
	pq->size = 0;
}

void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);

	//创建链表，尾插
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	//检查空间开辟失败的情况
	if (newnode == NULL)
	{
		perror("malloc fail");
		return;
	}
	newnode->data = x;
	newnode->next = NULL;

	if (pq->front == NULL)
	{
		assert(pq->rear == NULL);

		pq->front = pq->rear = newnode;
	}
	else
	{
		pq->rear->next = newnode;
		pq->rear = pq->rear->next;
	}

	pq->size++;
}

void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!IsEmpty(pq));

	//1、仅有一个节点时
	if (pq->front->next == NULL)
	{
		free(pq->front);
		pq->front = pq->rear = NULL;
	}
	//2、有多个节点时
	else
	{
		//1、仅有一个节点使用此方法时，会使pq->rear变成野指针
		QNode* next = pq->front->next;
		free(pq->front);
		pq->front = next;
	}
	pq->size--;
}

QDataType QueueFront(Queue* pq)
{
	assert(pq);

	return pq->front->data;
}

QDataType QueueBack(Queue* pq)
{
	assert(pq);

	return pq->rear->data;
}

int QueueSize(Queue* pq)
{
	assert(pq);

	return pq->size;
}

bool IsEmpty(Queue* pq)
{
	assert(pq);

	return pq->front == NULL && pq->rear == NULL;
	//return pq->size == 0;
}

void QueueDestroy(Queue* pq)
{
	assert(pq);

	QNode* cur = pq->front;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->size = 0;
}

typedef struct {
	Queue q1;
	Queue q2;
} MyStack;


MyStack* myStackCreate() {
	MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
	if (obj == NULL)
	{
		perror("malloc fail");
		return NULL;
	}

	QueueInit(&obj->q1);
	QueueInit(&obj->q2);

	return obj;
}

void myStackPush(MyStack* obj, int x) {
	//第一次入栈
	if (!IsEmpty(&obj->q1) && !IsEmpty(&obj->q2))
	{
		QueuePush(&obj->q1, x);
	}
	//第二次入栈
	if (!IsEmpty(&obj->q1))
	{
		QueuePush(&obj->q1, x);
	}
	else
	{
		QueuePush(&obj->q2, x);
	}

}

int myStackPop(MyStack* obj) {
	//假设队列1为空
	MyStack* Empty = &obj->q1;
	MyStack* NEmpty = &obj->q2;
	if (!IsEmpty(Empty))
	{
		Empty = &obj->q2;
		NEmpty = &obj->q1;
	}
	while (QueueSize(NEmpty) > 1)
	{
		QueuePush(Empty, QueueFront(NEmpty));
		//导一个删一个
		QueuePop(NEmpty);
	}

	int pop = QueueBack(NEmpty);
	QueuePop(NEmpty);
	return pop;
}

int myStackTop(MyStack* obj) {
	if (!IsEmpty(&obj->q1))
		return QueueBack(&obj->q1);
	else
		return QueueBack(&obj->q2);
}

bool myStackEmpty(MyStack* obj) {
	//两个队列都为空才为空
	return IsEmpty(&obj->q1) && IsEmpty(&obj->q2);
}

void myStackFree(MyStack* obj) {
	QueueDestroy(&obj->q1);
	QueueDestroy(&obj->q2);
	free(obj);
}