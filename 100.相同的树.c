/*
 * @lc app=leetcode.cn id=100 lang=c
 *
 * [100] 相同的树
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


bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    
    if (p == NULL && q == NULL)
    {
        return true;
    }
    else if ( p != NULL && q != NULL)
    {
        if (p->val != q->val)
        {
            return false;
        }
        if (!isSameTree(p->left, q->left))
        {
            return false;
        }
        if (!isSameTree(p->right, q->right))
        {
            return false;
        }
        return true;
    }

    return false;
}
// @lc code=end

