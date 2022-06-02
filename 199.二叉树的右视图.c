/*
 * @lc app=leetcode.cn id=199 lang=c
 *
 * [199] 二叉树的右视图
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

void rightSide(struct TreeNode* root,int *ret, int* returnSize, int depth)
{
    if( root != NULL)
    {
        if (depth == *returnSize)
        {
            ret[(*returnSize)++] = root->val;
        }

        rightSide(root->right, ret, returnSize, depth + 1);
        rightSide(root->left, ret, returnSize, depth + 1);
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* rightSideView(struct TreeNode* root, int* returnSize)
{
    *returnSize = 0;
    int *ret = NULL;
    if (root != NULL)
    {
        ret = (int *)malloc(sizeof(int) * 100);
         rightSide(root, ret, returnSize, 0);
    }
    return ret;
}
// @lc code=end

