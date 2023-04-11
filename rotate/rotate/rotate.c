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
    //如果k大于数组长度
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
    //输入数组的个数
    printf("请输入数组的个数:>");
    scanf("%d", &n);
    //输入左旋的个数
    printf("请输入左旋的个数:>");
    scanf("%d", &k);
    //输入数组元素
    printf("请输入数组元素:>");
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