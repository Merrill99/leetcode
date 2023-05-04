#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//方法一：暴力求解，分别遍历然后比较，时间复杂度O(N)
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

//方法二：先找到尾结点比较是否相等，如果相等则证明必然相交
//其次，求出两个链表的长度 然后相减，让长链表先走差值步，最后两个链表一起走，遇到相等的结点，则找到交叉结点
//时间复杂度O(N+M)

struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    struct ListNode* tailA = headA, * tailB = headB;
    int lenA = 1, lenB = 1;
    //遍历链表A,找到尾并记录长度
    while (tailA->next)
    {
        tailA = tailA->next;
        ++lenA;
    }
    //遍历链表B，找到尾并记录长度
    while (tailB->next)
    {
        tailB = tailB->next;
        ++lenB;
    }
    //判断是否相交
    if (tailA != tailB)
    {
        return NULL;
    }
    //假设A链表是长链表
    struct ListNode* longlist = headA;
    struct ListNode* shortlist = headB;
    //如果A不是长链表，则进行交换
    if (lenA < lenB)
    {
        longlist = headB;
        shortlist = headA;
    }
    int gap = abs(lenA - lenB);
    //让长链表先走gap步
    while (gap--)
    {
        longlist = longlist->next;
    }
    //然后同时开始走
    while (longlist != shortlist)
    {
        longlist = longlist->next;
        shortlist = shortlist->next;
    }
    //最后任意返回一个结点
    return shortlist;
}