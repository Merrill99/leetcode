#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* rhead = NULL, * cur = head;
    //±éÀú
    while (cur)
    {
        struct ListNode* next = cur->next;
        cur->next = rhead;
        rhead = cur;
        cur = next;
        if (next)
            next = next->next;
    }
    return rhead;
}