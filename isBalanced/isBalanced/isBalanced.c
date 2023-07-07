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

    // ���������ߣ���¼���Ƚ������������
    int left = BinaryTreeHeight(root->left);
    int right = BinaryTreeHeight(root->right);
    // ������Ƚ�����ǿ�����+1(+1�൱����һ�㵽�Լ��ĸ߶�)
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