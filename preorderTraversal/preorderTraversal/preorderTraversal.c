#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

int BTSize(struct TreeNode* root)
{
    return root == NULL ? 0 : BTSize(root->left) + BTSize(root->right) + 1;
}

void _preorderTraversal(struct TreeNode* root, int* arr, int* pi)
{
    if (root == NULL)
        return;

    arr[*pi] = root->val;
    ++(*pi);

    _preorderTraversal(root->left, arr, pi);
    _preorderTraversal(root->right, arr, pi);

}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {

    *returnSize = BTSize(root);
    // ��������
    int* array = (int*)malloc(*returnSize * sizeof(int));

    int i = 0;
    // ǰ����������ݷ�������
    _preorderTraversal(root, array, &i);
    return array;
}