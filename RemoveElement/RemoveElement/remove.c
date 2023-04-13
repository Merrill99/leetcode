#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int removeElement(int* nums, int numsSize, int val) 
{
    int i = 0;
    //记录初始长度
    int len = numsSize;
    int tmp = 0;
    for (i = 0; i < numsSize; ++i)
    {
        if (nums[i] != val)
        {
            nums[tmp++] = nums[i];
        }
        //相等，长度-1
        else
        {
            len--;
        }
    }
    return len;
}

int main()
{
    int nums[20] = { 0 };
    int n = 0;
    //输入一个不超过数组长度的数字
    printf("请输入数组的长度:>");
    scanf("%d", &n);
    printf("nums=");
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &nums[i]);
    }
    int val = 0;
    printf("请输入要删除的数字:>");
    scanf("%d", &val);
    int len = removeElement(nums, n, val);
    for (int i = 0; i < len; ++i)
    {
        printf("%d ", nums[i]);
    }
    return 0;
}