#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

void reverse(int* left, int* right)
{
    while (left < right)
    {
        int tmp = *left;
        *left = *right;
        *right = tmp;
        left++;
        right--;
    }
}
void rotate(int* nums, int numsSize, int k) 
{
    //���k�������鳤��
    if (k > numsSize)
    {
        k %= numsSize;
    }
    reverse(nums, nums + numsSize - 1);
    reverse(nums, nums + k - 1);
    reverse(nums + k, nums + numsSize - 1);
}

int main()
{
    int nums[20] = { 0 };
    int k = 0;
    int n = 0;
    //��������ĸ���
    printf("����������ĸ���:>");
    scanf("%d", &n);
    //���������ĸ���
    printf("�����������ĸ���:>");
    scanf("%d", &k);
    //��������Ԫ��
    printf("����������Ԫ��:>");
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &nums[i]);
    }
    rotate(nums, n, k);
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", nums[i]);
    }
    return 0;
}