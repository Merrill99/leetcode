#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    // ������Ϊ����
    if (p == NULL && q == NULL)
        return true;

    // �ߵ���һ����˵����������һ������Ϊ��
    // �����һ����Ϊ����֤���������������
    if (p == NULL || q == NULL)
        return false;

    if (p->val != q->val)
        return false;

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
    // �ߵ��ջ�δ�ҵ���������֤��������
    if (root == NULL)
        return false;
    // �ж��Ƿ�Ϊ����
    if (isSameTree(root, subRoot))
        return true;

    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}