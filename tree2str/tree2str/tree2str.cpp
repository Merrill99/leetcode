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

        // ��val������ת����string
        str += to_string(root->val);

        // ��������
        if (root->left || root->right)
        {
            str += '(';
            str += tree2str(root->left);
            str += ')';
        }

        // ��������
        if (root->right)
        {
            str += '(';
            str += tree2str(root->right);
            str += ')';
        }

        return str;
    }
};