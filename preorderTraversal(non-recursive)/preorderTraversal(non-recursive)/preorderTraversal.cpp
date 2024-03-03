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

        // cur����stack��Ϊ��
        while (cur || !st.empty())
        {
            // cur��Ϊ�շŽ�vector����ջ
            while (cur)
            {
                v.push_back(cur->val);
                st.push(cur);
                cur = cur->left;
            }
            // ��¼ջ��Ԫ��
            TreeNode* top = st.top();
            // ��ջ��Ԫ�س�ջ
            st.pop();
            // ����cur
            cur = top->right;
        }
        return v;
    }
};