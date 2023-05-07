#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* detectCycle(struct ListNode* head) {
    struct ListNode* slow = head, * fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        //��¼������
        if (slow == fast)
        {
            struct ListNode* meet = slow;
            //����ڵ�
            while (head != slow)
            {
                head = head->next;
                slow = slow->next;
            }
            return head;
        }
    }
    return NULL;
}