#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    // 两个都为空树
    if (p == NULL && q == NULL)
        return true;

    // 走到这一步，说明有至少有一个树不为空
    // 如果有一个树为空则证明这两个树不相等
    if (p == NULL || q == NULL)
        return false;

    if (p->val != q->val)
        return false;

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
    // 走到空还未找到子树，则证明不存在
    if (root == NULL)
        return false;
    // 判断是否为子树
    if (isSameTree(root, subRoot))
        return true;

    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}