#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

//����һ
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

//������������ָ��
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast && fast->next)
    {
        //slow��һ����fast������
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}