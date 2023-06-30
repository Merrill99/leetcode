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
    // �������������Ϊ�գ����ǶԳƶ�����
    if (rootleft == NULL && rootright == NULL)
        return true;
    // ������һ����Ϊ�գ������һ��Ϊ�գ����ǶԳƶ�����
    if (rootleft == NULL || rootright == NULL)
        return false;
    // ����Ϊ�գ��ֱ�Ƚ����������������Ƿ����
    if (rootleft->val != rootright->val)
        return false;
    return _isSymmetric(rootleft->left, rootright->right)
        && _isSymmetric(rootleft->right, rootright->left);
}

bool isSymmetric(struct TreeNode* root) {

    return _isSymmetric(root->left, root->right);
}