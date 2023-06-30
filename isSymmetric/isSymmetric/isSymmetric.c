#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

bool _isSymmetric(struct TreeNode* rootleft, struct TreeNode* rootright)
{
    // 如果左右子树都为空，则是对称二叉树
    if (rootleft == NULL && rootright == NULL)
        return true;
    // 至少有一个不为空，如果有一个为空，则不是对称二叉树
    if (rootleft == NULL || rootright == NULL)
        return false;
    // 都不为空，分别比较左子树和右子树是否相等
    if (rootleft->val != rootright->val)
        return false;
    return _isSymmetric(rootleft->left, rootright->right)
        && _isSymmetric(rootleft->right, rootright->left);
}

bool isSymmetric(struct TreeNode* root) {

    return _isSymmetric(root->left, root->right);
}