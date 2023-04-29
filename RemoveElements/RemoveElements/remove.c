#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

//����һ
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* cur = head;
    struct ListNode* prev = NULL;
    //����
    while (cur)
    {
        //�ж��Ƿ���Ҫɾ��Ԫ��
        if (cur->val == val)
        {
            //�����һ��Ԫ����Ҫɾ�������ͷɾ
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

//������
//������ǰ�����Ѳ���val������β��
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* cur = head;
    struct ListNode* newhead = NULL, * tail = NULL;
    //����
    while (cur)
    {
        //���������Ϊɾ����Ԫ�أ������β��
        if (cur->val != val)
        {
            //��һ�ν���β��
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
            //��¼��ǰ��Ҫɾ����Ԫ��
            struct ListNode* del = cur;
            cur = cur->next;
            free(del);
        }
    }
    return newhead;
}
