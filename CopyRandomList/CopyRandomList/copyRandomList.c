#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

struct Node {
    int val;
    struct Node* next;
    struct Node* random;
};

//方法一：暴力比较
struct Node* copyRandomList(struct Node* head) {
    struct Node* newhead = NULL, * newcur = NULL;
    struct Node* cur = head;
    //遍历原链表，并创建新链表
    while (cur)
    {
        struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
        if (newhead == NULL)
        {
            newhead = newcur = newnode;
            newnode->next = NULL;
        }
        else
        {
            newcur->next = newnode;
            newcur = newcur->next;
            newnode->next = NULL;
        }
        cur = cur->next;
    }
    cur = head;
    newcur = newhead;
    while (cur)
    {
        //创建临时指针挨个进行比较
        struct Node* tmp = head;
        struct Node* newtmp = newhead;
        while (tmp)
        {
            //逐个与cur->val比较，确定random连接的位置
            if (cur->random == NULL)
            {
                newcur->random = NULL;
                break;
            }
            else if (cur->random == tmp)
            {
                newcur->random = newtmp;
                break;
            }
            tmp = tmp->next;
            newtmp = newtmp->next;
        }
        //将值放入新链表中
        newcur->val = cur->val;
        newcur = newcur->next;
        cur = cur->next;
    }
    return newhead;
}

//方法二
struct Node* copyRandomList(struct Node* head) {
    struct Node* cur = head;
    //1、在原节点之后插入复制节点
    while (cur)
    {
        struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
        struct Node* next = cur->next;
        cur->next = copy;
        copy->next = next;
        cur = next;
    }
    cur = head;
    //2、控制复制节点的random,并放入val
    while (cur)
    {
        struct Node* copy = cur->next;
        struct Node* next = cur->next->next;
        if (cur->random == NULL)
        {
            copy->random = NULL;
        }
        else
        {
            copy->random = cur->random->next;
        }
        copy->val = cur->val;
        cur = next;
    }
    //3、将复制节点挨个位置，并恢复原链表的链接
    cur = head;
    struct Node* copyhead = NULL, * copytail = NULL;
    while (cur)
    {
        struct Node* copy = cur->next;
        struct Node* next = cur->next->next;
        //尾插复制链表
        if (copyhead == NULL)
        {
            copyhead = copytail = copy;
        }
        else
        {
            copytail->next = copy;
            copytail = copytail->next;
        }
        //恢复原链表
        cur->next = next;
        cur = next;
    }
    return copyhead;
}