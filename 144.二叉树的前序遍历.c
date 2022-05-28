/*
 * @lc app=leetcode.cn id=144 lang=c
 *
 * [144] 二叉树的前序遍历
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


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void preorder(struct TreeNode* root, int*ret, int* returnSize)
{
    if (root == NULL)
    {
        return NULL;
    }
    else
    {
        ret[(*returnSize)++] = root->val;
        preorder(root->left, ret, returnSize);
        preorder(root->right, ret, returnSize);
    }
}

int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
    *returnSize = 0;
    if (root == NULL)
    {
        return NULL;
    }
    else
    {
        int *ret = (int *)malloc(sizeof(int) * 100);
        preorder(root, ret, returnSize);
        return ret;
    }
}
// @lc code=end

