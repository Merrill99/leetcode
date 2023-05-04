#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//����һ��������⣬�ֱ����Ȼ��Ƚϣ�ʱ�临�Ӷ�O(N)
struct ListNode {
    int val;
    struct ListNode* next;
};
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    struct ListNode* curA = headA, * curB = headB;
    while (curA)
    {
        curB = headB;
        while (curB)
        {
            if (curA == curB)
            {
                return curA;
            }
            else
            {
                curB = curB->next;
            }
        }
        curA = curA->next;
    }
    return NULL;
}

//�����������ҵ�β���Ƚ��Ƿ���ȣ���������֤����Ȼ�ཻ
//��Σ������������ĳ��� Ȼ��������ó��������߲�ֵ���������������һ���ߣ�������ȵĽ�㣬���ҵ�������
//ʱ�临�Ӷ�O(N+M)

struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    struct ListNode* tailA = headA, * tailB = headB;
    int lenA = 1, lenB = 1;
    //��������A,�ҵ�β����¼����
    while (tailA->next)
    {
        tailA = tailA->next;
        ++lenA;
    }
    //��������B���ҵ�β����¼����
    while (tailB->next)
    {
        tailB = tailB->next;
        ++lenB;
    }
    //�ж��Ƿ��ཻ
    if (tailA != tailB)
    {
        return NULL;
    }
    //����A�����ǳ�����
    struct ListNode* longlist = headA;
    struct ListNode* shortlist = headB;
    //���A���ǳ���������н���
    if (lenA < lenB)
    {
        longlist = headB;
        shortlist = headA;
    }
    int gap = abs(lenA - lenB);
    //�ó���������gap��
    while (gap--)
    {
        longlist = longlist->next;
    }
    //Ȼ��ͬʱ��ʼ��
    while (longlist != shortlist)
    {
        longlist = longlist->next;
        shortlist = shortlist->next;
    }
    //������ⷵ��һ�����
    return shortlist;
}