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
	int size;//��¼���ݸ���
}Queue;

//��ʼ������ 
void QueueInit(Queue* pq);
//��β��ӣ�β�壩
void QueuePush(Queue* pq, QDataType x);
//��ͷ���ӣ�ͷɾ��
void QueuePop(Queue* pq);
//��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* pq);
//��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* pq);
//��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* pq);
//�ж������Ƿ�Ϊ��
bool IsEmpty(Queue* pq);
//���ٶ��� 
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

	//��������β��
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	//���ռ俪��ʧ�ܵ����
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

	//1������һ���ڵ�ʱ
	if (pq->front->next == NULL)
	{
		free(pq->front);
		pq->front = pq->rear = NULL;
	}
	//2���ж���ڵ�ʱ
	else
	{
		//1������һ���ڵ�ʹ�ô˷���ʱ����ʹpq->rear���Ұָ��
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
	//��һ����ջ
	if (!IsEmpty(&obj->q1) && !IsEmpty(&obj->q2))
	{
		QueuePush(&obj->q1, x);
	}
	//�ڶ�����ջ
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
	//�������1Ϊ��
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
		//��һ��ɾһ��
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
	//�������ж�Ϊ�ղ�Ϊ��
	return IsEmpty(&obj->q1) && IsEmpty(&obj->q2);
}

void myStackFree(MyStack* obj) {
	QueueDestroy(&obj->q1);
	QueueDestroy(&obj->q2);
	free(obj);
}