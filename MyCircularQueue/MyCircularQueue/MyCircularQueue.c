#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct {
    int* arr;
    int front;
    int rear;
    int k;//数据个数
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
    //判满
    if (myCircularQueueIsFull(obj))
        return false;

    obj->arr[obj->rear++] = value;
    //如果rear在最后一位，++后超过了数组的长度
    obj->rear %= obj->k + 1;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    //判空
    if (myCircularQueueIsEmpty(obj))
        return false;

    obj->arr[obj->front++];
    //如果front在最后一位，++后超过了数组的长度
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

    //队尾元素，rear的前一个，当rear在第一位时，会出现越界的情况
    //用(rear+k)%(k+1)处理即可
    return obj->arr[(obj->rear + obj->k) % (obj->k + 1)];
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->arr);
    free(obj);
}