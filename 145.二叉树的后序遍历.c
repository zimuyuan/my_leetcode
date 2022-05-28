/*
 * @lc app=leetcode.cn id=145 lang=c
 *
 * [145] 二叉树的后序遍历
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
void postorder(struct TreeNode* root, int*ret, int* returnSize)
{
    if (root == NULL)
    {
        return NULL;
    }
    else
    {
        postorder(root->left, ret, returnSize);
        postorder(root->right, ret, returnSize);
        ret[(*returnSize)++] = root->val;
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* postorderTraversal(struct TreeNode* root, int* returnSize){
    *returnSize = 0;
    if (root == NULL)
    {
        return NULL;
    }
    else
    {
        int *ret = (int *)malloc(sizeof(int) * 100);
        postorder(root, ret, returnSize);
        return ret;
    }
}
// @lc code=end

