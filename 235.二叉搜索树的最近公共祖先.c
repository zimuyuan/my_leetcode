/*
 * @lc app=leetcode.cn id=235 lang=c
 *
 * [235] 二叉搜索树的最近公共祖先
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

struct TreeNode* lowestCommon(struct TreeNode* root, int min, int max) 
{
    if (root->val > max)
    {
        return lowestCommon(root->left, min, max);
    }
    else if (root->val < min)
    {
        return lowestCommon(root->right, min, max);
    }
    else
    {
        return root;
    }
}
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) 
{
    if ( root == NULL)
    {
        return NULL;
    }
    else
    {
        int max = 0;
        int min = 0;
        if (p->val > q->val)
        {
            max = p->val;
            min = q->val;
        }
        else
        {
            max = q->val;
            min = p->val;
        }
        return lowestCommon(root, min, max);
    }
    
}
// @lc code=end

