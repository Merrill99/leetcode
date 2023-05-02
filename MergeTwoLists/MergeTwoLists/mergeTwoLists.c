#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* cur1 = list1, * cur2 = list2;
    struct ListNode* newhead = NULL, * tail = NULL;
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;
    while (cur1 && cur2)
    {
        //比较小的进行尾插
        if (cur1->val < cur2->val)
        {
            if (newhead == NULL)
            {
                newhead = tail = cur1;
            }
            else
            {
                tail->next = cur1;
                tail = tail->next;
            }
            cur1 = cur1->next;

        }
        else
        {
            if (newhead == NULL)
            {
                newhead = tail = cur2;
            }
            else
            {
                tail->next = cur2;
                tail = tail->next;
            }
            cur2 = cur2->next;

        }
    }
    if (cur1)
    {
        tail->next = cur1;
    }
    else
    {
        tail->next = cur2;
    }
    return newhead;
}