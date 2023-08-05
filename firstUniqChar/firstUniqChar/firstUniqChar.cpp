#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int str[26] = { 0 };
        int left = 0;
        while (left < s.size())
        {
            str[s[left] - 'a']++;
            ++left;
        }
        left = 0;
        while (left < s.size())
        {
            if (str[s[left] - 'a'] == 1)
            {
                return left;
            }
            ++left;
        }
        // Ã»ÕÒµ½£¬·µ»Ø-1
        return -1;
    }
};