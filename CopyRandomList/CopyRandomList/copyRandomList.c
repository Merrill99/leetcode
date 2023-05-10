#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

struct Node {
    int val;
    struct Node* next;
    struct Node* random;
};

//����һ�������Ƚ�
struct Node* copyRandomList(struct Node* head) {
    struct Node* newhead = NULL, * newcur = NULL;
    struct Node* cur = head;
    //����ԭ����������������
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
        //������ʱָ�밤�����бȽ�
        struct Node* tmp = head;
        struct Node* newtmp = newhead;
        while (tmp)
        {
            //�����cur->val�Ƚϣ�ȷ��random���ӵ�λ��
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
        //��ֵ������������
        newcur->val = cur->val;
        newcur = newcur->next;
        cur = cur->next;
    }
    return newhead;
}

//������
struct Node* copyRandomList(struct Node* head) {
    struct Node* cur = head;
    //1����ԭ�ڵ�֮����븴�ƽڵ�
    while (cur)
    {
        struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
        struct Node* next = cur->next;
        cur->next = copy;
        copy->next = next;
        cur = next;
    }
    cur = head;
    //2�����Ƹ��ƽڵ��random,������val
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
    //3�������ƽڵ㰤��λ�ã����ָ�ԭ���������
    cur = head;
    struct Node* copyhead = NULL, * copytail = NULL;
    while (cur)
    {
        struct Node* copy = cur->next;
        struct Node* next = cur->next->next;
        //β�帴������
        if (copyhead == NULL)
        {
            copyhead = copytail = copy;
        }
        else
        {
            copytail->next = copy;
            copytail = copytail->next;
        }
        //�ָ�ԭ����
        cur->next = next;
        cur = next;
    }
    return copyhead;
}