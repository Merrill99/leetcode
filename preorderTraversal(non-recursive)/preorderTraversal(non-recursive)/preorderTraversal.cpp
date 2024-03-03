#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> v;

        TreeNode* cur = root;

        // cur或者stack不为空
        while (cur || !st.empty())
        {
            // cur不为空放进vector并入栈
            while (cur)
            {
                v.push_back(cur->val);
                st.push(cur);
                cur = cur->left;
            }
            // 记录栈顶元素
            TreeNode* top = st.top();
            // 将栈顶元素出栈
            st.pop();
            // 更新cur
            cur = top->right;
        }
        return v;
    }
};