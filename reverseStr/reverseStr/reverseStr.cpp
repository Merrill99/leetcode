#include<iostream>

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        // ��ת�� 2k �ַ��е�ǰ k ���ַ�
        for (int i = 0; i < s.size(); i += (2 * k))
        {
            // ���ʣ����ַ�����k����ȫ����ת
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