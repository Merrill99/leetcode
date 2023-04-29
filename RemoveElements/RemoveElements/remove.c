#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

//方法一
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* cur = head;
    struct ListNode* prev = NULL;
    //遍历
    while (cur)
    {
        //判断是否需要删除元素
        if (cur->val == val)
        {
            //如果第一个元素需要删除，则进头删
            if (prev == NULL)
            {
                cur = cur->next;
                free(head);
                head = cur;
            }
            else
            {
                prev->next = cur->next;
                free(cur);
                cur = prev->next;
            }
        }
        else
        {
            prev = cur;
            cur = cur->next;
        }
    }
    return head;
}

//方法二
//遍历当前链表，把不是val的拿来尾插
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* cur = head;
    struct ListNode* newhead = NULL, * tail = NULL;
    //遍历
    while (cur)
    {
        //遍历如果不为删除的元素，则进行尾插
        if (cur->val != val)
        {
            //第一次进行尾插
            if (newhead == NULL)
            {
                newhead = tail = cur;
            }
            else
            {
                tail->next = cur;
                tail = tail->next;
            }
            cur = cur->next;
            tail->next = NULL;
        }
        else
        {
            //记录当前所要删除的元素
            struct ListNode* del = cur;
            cur = cur->next;
            free(del);
        }
    }
    return newhead;
}
