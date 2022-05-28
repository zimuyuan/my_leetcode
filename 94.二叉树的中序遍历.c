/*
 * @lc app=leetcode.cn id=94 lang=c
 *
 * [94] 二叉树的中序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void inorder(struct TreeNode* root, int*ret, int* returnSize)
{
    if (root == NULL)
    {
        return NULL;
    }
    else
    {
        inorder(root->left, ret, returnSize);
        ret[(*returnSize)++] = root->val;
        inorder(root->right, ret, returnSize);
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    *returnSize = 0;
    if (root == NULL)
    {
        return NULL;
    }
    else
    {
        int *ret = (int *)malloc(sizeof(int) * 100);
        inorder(root, ret, returnSize);
        return ret;
    }
}
// @lc code=end

