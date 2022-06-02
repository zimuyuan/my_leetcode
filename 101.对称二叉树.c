/*
 * @lc app=leetcode.cn id=101 lang=c
 *
 * [101] 对称二叉树
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

bool isSymmetricSub(struct TreeNode* rLeft, struct TreeNode* rRight)
{
    if (rLeft == NULL && rRight == NULL)
    {
        return true;
    }
    else if (rLeft != NULL && rRight != NULL)
    {
        if (rLeft->val == rRight->val)
        {
            return isSymmetricSub(rLeft->left, rRight->right) && isSymmetricSub(rLeft->right, rRight->left);
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
    
}

bool isSymmetric(struct TreeNode* root)
{
    if (root == NULL)
    {
        return true;
    }
    else
    {
        return isSymmetricSub(root->left, root->right);
    }
}
// @lc code=end

