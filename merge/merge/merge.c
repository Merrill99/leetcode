#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) 
{
    int tmp[m + n];
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < m && j < n && k < m + n)
    {
        if (nums1[i] < nums2[j])
        {
            tmp[k] = nums1[i++];
            ++k;
        }
        else
        {
            tmp[k] = nums2[j++];
            ++k;
        }
    }
    //���������������
    if (i == m)
    {
        for (; j < n; ++j)
        {
            tmp[k] = nums2[j];
            ++k;
        }
    }
    else
    {
        for (; i < m; ++i)
        {
            tmp[k] = nums1[i];
            ++k;
        }
    }
    //����ʱ�����е�Ԫ�ظ���nums1
    for (k = 0; k < m + n; ++k)
    {
        nums1[k] = tmp[k];
    }
}