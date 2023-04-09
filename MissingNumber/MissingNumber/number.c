#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//方法一：异或
int missingNumber(int* nums, int numsSize) 
{
    int x = 0;
    int i = 0;
    for (i = 0; i < numsSize; ++i)
    {
        x ^= nums[i];
    }
    for (i = 0; i < numsSize + 1; ++i)
    {
        x ^= i;
    }
    return x;
}

//方法二：等差数列挨个减
//int missingNumber(int* nums, int numsSize) 
//{
//    //运用等差数列公式计算数组的和
//    int x = (0 + numsSize) * (numsSize + 1) / 2;
//    for (int i = 0; i < numsSize; ++i)
//    {
//        x -= nums[i];
//    }
//    return x;
//}

int main()
{
    int n = 0;
    int nums[100] = { 0 };
    scanf("%d", &n);
    //任意输入0~n的数，其中缺一个数
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &nums[i]);
    }
    printf("%d\n", missingNumber(nums, n));
    return 0;
}