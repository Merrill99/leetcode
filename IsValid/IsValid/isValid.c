#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef char STDataType;
typedef struct Stack
{
    STDataType* arr;
    int top;//ջ��
    int capacity;//����
}Stack;

//ջ�ĳ�ʼ��
void STIniti(Stack* pst);
//ѹջ
void STPush(Stack* pst, STDataType x);
//��ջ
void STPop(Stack* pst);
//�п�
bool IsEmpty(Stack* pst);
//��ȡջ��Ԫ�� 
STDataType STTop(Stack* pst);
// ��ȡջ����ЧԪ�ظ��� 
int STSize(Stack* pst);
//����ջ
void STDestroy(Stack* pst);

void STIniti(Stack* pst)
{
    assert(pst);

    pst->arr = NULL;
    pst->capacity = 0;
    //topָ��ջ�����ݵ���һ��λ��
    pst->top = 0;
}

void STPush(Stack* pst, STDataType x)
{
    assert(pst);

    if (pst->capacity == pst->top)
    {
        //(pst->capacity == 0) ? (pst->capacity = 4) : (pst->capacity *= 2);
        int newcapacity = pst->capacity == 0 ? 4 : pst->capacity * 2;
        STDataType* tmp = (STDataType*)realloc(pst->arr, newcapacity * sizeof(STDataType));
        if (tmp == NULL)
        {
            perror("realloc fail");
            return;
        }
        pst->arr = tmp;
        pst->capacity = newcapacity;
    }

    pst->arr[pst->top++] = x;
}

bool IsEmpty(Stack* pst)
{
    assert(pst);

    return pst->top == 0;
}

void STPop(Stack* pst)
{
    assert(pst);
    //�п�
    assert(!IsEmpty(pst));

    pst->top--;
}

STDataType STTop(Stack* pst)
{
    assert(pst);
    assert(!IsEmpty(pst));

    return pst->arr[pst->top - 1];
}

int STSize(Stack* pst)
{
    assert(pst);

    return pst->top;
}

void STDestroy(Stack* pst)
{
    assert(pst);

    pst->capacity = 0;
    pst->top = 0;
    free(pst->arr);
}

bool isValid(char* s) {
    //����ջ
    Stack st;
    STIniti(&st);

    while (*s)
    {
        //������������ջ
        if (*s == '(' || *s == '[' || *s == '{')
        {
            STPush(&st, *s);
        }
        //���������ţ������ų�ջ�Ƚ�
        else
        {
            if (IsEmpty(&st))
                return false;
            char top = STTop(&st);
            //��ջ
            STPop(&st);
            //��ͬ������false
            if (*s == ')' && top != '(' ||
                *s == ']' && top != '[' ||
                *s == '}' && top != '{')
                return false;
        }
        ++s;
    }
    if (!IsEmpty(&st))
        return false;

    return true;

    STDestroy(&st);
}