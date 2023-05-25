#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct {
    int* arr;
    int front;
    int rear;
    int k;//���ݸ���
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    obj->arr = (int*)malloc((k + 1) * sizeof(int));
    obj->front = obj->rear = 0;
    obj->k = k;
    return obj;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->front == obj->rear;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->front == (obj->rear + 1) % (obj->k + 1);
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    //����
    if (myCircularQueueIsFull(obj))
        return false;

    obj->arr[obj->rear++] = value;
    //���rear�����һλ��++�󳬹�������ĳ���
    obj->rear %= obj->k + 1;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    //�п�
    if (myCircularQueueIsEmpty(obj))
        return false;

    obj->arr[obj->front++];
    //���front�����һλ��++�󳬹�������ĳ���
    obj->front %= obj->k + 1;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return -1;

    return obj->arr[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return -1;

    //��βԪ�أ�rear��ǰһ������rear�ڵ�һλʱ�������Խ������
    //��(rear+k)%(k+1)������
    return obj->arr[(obj->rear + obj->k) % (obj->k + 1)];
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->arr);
    free(obj);
}