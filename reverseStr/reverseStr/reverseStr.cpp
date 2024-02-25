#include<iostream>

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        // 反转这 2k 字符中的前 k 个字符
        for (int i = 0; i < s.size(); i += (2 * k))
        {
            // 如果剩余的字符少于k个则全部反转
            if (s.size() - i < k)
            {
                reverse(s.begin() + i, s.begin() + s.size());
                break;
            }
            reverse(s.begin() + i, s.begin() + i + k);
        }
        return s;
    }
};