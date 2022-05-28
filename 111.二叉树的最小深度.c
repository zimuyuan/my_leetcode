/*
 * @lc app=leetcode.cn id=111 lang=c
 *
 * [111] 二叉树的最小深度
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


int minDepth(struct TreeNode* root){
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        int lmindepth = minDepth(root->left);
        int rmindepth = minDepth(root->right);
        if (lmindepth != 0 && rmindepth != 0)
        {
            return 1 + (lmindepth < rmindepth ? lmindepth : rmindepth);
        }
        else
        {
            return 1 + (lmindepth > rmindepth ? lmindepth : rmindepth);
        }
        
    }
}
// @lc code=end

