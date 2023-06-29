#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

bool isUnivalTree(struct TreeNode* root) {
    if (root == NULL)
        return true;

    // 比较左树
    if (root->left && root->val != root->left->val)
        return false;
    // 比较右树
    if (root->right && root->val != root->right->val)
        return false;

    return isUnivalTree(root->left) && isUnivalTree(root->right);
}