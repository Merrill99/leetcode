#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef char STDataType;
typedef struct Stack
{
    STDataType* arr;
    int top;//栈顶
    int capacity;//容量
}Stack;

//栈的初始化
void STIniti(Stack* pst);
//压栈
void STPush(Stack* pst, STDataType x);
//出栈
void STPop(Stack* pst);
//判空
bool IsEmpty(Stack* pst);
//获取栈顶元素 
STDataType STTop(Stack* pst);
// 获取栈中有效元素个数 
int STSize(Stack* pst);
//销毁栈
void STDestroy(Stack* pst);

void STIniti(Stack* pst)
{
    assert(pst);

    pst->arr = NULL;
    pst->capacity = 0;
    //top指向栈顶数据的下一个位置
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
    //判空
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
    //创建栈
    Stack st;
    STIniti(&st);

    while (*s)
    {
        //遇见左括号入栈
        if (*s == '(' || *s == '[' || *s == '{')
        {
            STPush(&st, *s);
        }
        //遇见右括号，左括号出栈比较
        else
        {
            if (IsEmpty(&st))
                return false;
            char top = STTop(&st);
            //出栈
            STPop(&st);
            //不同，返回false
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