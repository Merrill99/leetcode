#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int removeElement(int* nums, int numsSize, int val) 
{
    int i = 0;
    //��¼��ʼ����
    int len = numsSize;
    int tmp = 0;
    for (i = 0; i < numsSize; ++i)
    {
        if (nums[i] != val)
        {
            nums[tmp++] = nums[i];
        }
        //��ȣ�����-1
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
    //����һ�����������鳤�ȵ�����
    printf("����������ĳ���:>");
    scanf("%d", &n);
    printf("nums=");
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &nums[i]);
    }
    int val = 0;
    printf("������Ҫɾ��������:>");
    scanf("%d", &val);
    int len = removeElement(nums, n, val);
    for (int i = 0; i < len; ++i)
    {
        printf("%d ", nums[i]);
    }
    return 0;
}