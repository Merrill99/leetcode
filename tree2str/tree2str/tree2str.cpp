#include<iostream>
#include<string>

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
    string tree2str(TreeNode* root) {
        string str;
        if (root == nullptr)
            return str;

        // 将val的类型转换成string
        str += to_string(root->val);

        // 遍历左树
        if (root->left || root->right)
        {
            str += '(';
            str += tree2str(root->left);
            str += ')';
        }

        // 遍历右树
        if (root->right)
        {
            str += '(';
            str += tree2str(root->right);
            str += ')';
        }

        return str;
    }
};