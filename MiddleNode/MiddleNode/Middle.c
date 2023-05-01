#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

//方法一
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* newhead = head;
    struct ListNode* cur = head;
    int n = 0;
    while (cur)
    {
        cur = cur->next;
        ++n;
    }
    int mid = n / 2;
    while (mid--)
    {
        newhead = newhead->next;
    }
    return newhead;
}

//方法二：快慢指针
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast && fast->next)
    {
        //slow走一步，fast走两步
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}