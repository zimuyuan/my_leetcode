/*
 * @lc app=leetcode.cn id=112 lang=c
 *
 * [112] 路径总和
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

bool hasSum(struct TreeNode* root, int targetSum)
{
    if (root == NULL)
    {
        return targetSum == 0;
    }
    else
    {
        if (root->left == NULL && root->right != NULL)
        {
            return hasSum(root->right, targetSum - root->val);
        }
        else if (root->right == NULL && root->left != NULL)
        {
            return hasSum(root->left, targetSum - root->val);
        }
        {
            return hasSum(root->left, targetSum - root->val) || hasSum(root->right, targetSum - root->val);
        }
    }
    
}
bool hasPathSum(struct TreeNode* root, int targetSum){
    if (root == NULL)
    {
        return false;
    }
    else
    {
        return hasSum(root, targetSum);
    }
}
// @lc code=end

