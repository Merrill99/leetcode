#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

int BinaryTreeHeight(struct TreeNode* root)
{
    if (root == NULL)
        return 0;

    // 继续向下走，记录并比较两棵树的深度
    int left = BinaryTreeHeight(root->left);
    int right = BinaryTreeHeight(root->right);
    // 返回深度较深的那棵树并+1(+1相当于上一层到自己的高度)
    return left > right ? left + 1 : right + 1;
}

bool isBalanced(struct TreeNode* root) {
    if (root == NULL)
        return true;

    int left = BinaryTreeHeight(root->left);
    int right = BinaryTreeHeight(root->right);

    if (abs(left - right) > 1)
        return false;

    return isBalanced(root->left) && isBalanced(root->right);
}