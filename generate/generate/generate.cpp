#define _CRT_SECURE_NO_WARNINGS 1
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vv(numRows);
        // 每行第一个元素和最后一个元素都为1
        for (size_t i = 0; i < vv.size(); ++i)
        {
            vv[i].resize(i + 1);
            vv[i][0] = vv[i][vv[i].size() - 1] = 1;
        }

        for (size_t i = 0; i < vv.size(); ++i)
        {
            for (size_t j = 0; j < vv[i].size(); ++j)
            {
                if (vv[i][j] != 1)
                {
                    // 该元素对应的上一行与前一个相加
                    vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
                }
            }
        }
        return vv;
    }
};