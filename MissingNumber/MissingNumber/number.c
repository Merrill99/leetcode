#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//����һ�����
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

//���������Ȳ����а�����
//int missingNumber(int* nums, int numsSize) 
//{
//    //���õȲ����й�ʽ��������ĺ�
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
    //��������0~n����������ȱһ����
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &nums[i]);
    }
    printf("%d\n", missingNumber(nums, n));
    return 0;
}