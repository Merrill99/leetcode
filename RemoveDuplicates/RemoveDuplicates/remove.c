#define _CRT_SECURE_NO_WARNINGS 1

int removeDuplicates(int* nums, int numsSize) 
{
    int src = 1, dest = 0;
    while (src < numsSize)
    {
        if (nums[dest] != nums[src])
        {
            nums[++dest] = nums[src++];
        }
        else
        {
            ++src;
        }
    }
    return dest + 1;
}