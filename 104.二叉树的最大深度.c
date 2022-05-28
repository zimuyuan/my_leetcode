/*
 * @lc app=leetcode.cn id=104 lang=c
 *
 * [104] 二叉树的最大深度
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
int max(int x, int y)
{
    return x > y ? x : y;
}

int maxDepth(struct TreeNode* root){
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
    
}
// @lc code=end

