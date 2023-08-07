#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int end1 = num1.size() - 1;
        int end2 = num2.size() - 1;
        int next = 0, sum = 0;
        string ret;
        while (end1 >= 0 || end2 >= 0)
        {
            // if (end1 >= 0 && end2 >= 0)
            // {
            //     sum = (num1[end1] - '0') + (num2[end2] - '0') + next;
            // }
            // else if (end1 >= 0)
            // {
            //     sum = (num1[end1] - '0') + next;
            // }
            // else if (end2 >= 0)
            // {
            //     sum = (num2[end2] - '0') + next;
            // }
            int x1 = end1 >= 0 ? num1[end1] - '0' : 0;
            int x2 = end2 >= 0 ? num2[end2] - '0' : 0;
            sum = x1 + x2 + next;
            // �жϽ�λ
            next = sum / 10;
            // ȡ��λ��
            sum %= 10;
            // ����������������ַ�����(β��)
            ret += (sum + '0');

            --end1;
            --end2;
        }
        if (1 == next)
            ret += '1';
        // ����
        reverse(ret.begin(), ret.end());
        return ret;
    }
};