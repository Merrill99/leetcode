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