/*
 * @lc app=leetcode.cn id=98 lang=c
 *
 * [98] 验证二叉搜索树
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

bool BST1(struct TreeNode* root, long long lower, long long upper)
{
    if (root == NULL)
    {
       return true;
    }
    if (root->val <= lower || root->val >= upper) 
    {
        return false;
    }
    return BST1(root->left, lower, root->val) && BST1(root->right, root->val, upper);
    
}

// 中序遍历二叉搜索树是升序的
bool BST2(struct TreeNode* root, long long *lower)
{
    if (root == NULL)
    {
        return true;
    }
    else
    {
        if (!BST2(root->left, lower))
        {
            return false;
        }
        if (root->val <= *lower)
        {
            return false;
        }
        *lower = root->val;
        return BST2(root->right, lower);
    }
}

bool isValidBST(struct TreeNode* root)
{

    // int MAX_INT = ((unsigned)(-1)) >> 1;
    // int MIN_INT = ~MAX_INT;
    // return BST(root, LONG_MIN, LONG_MAX);
    long long lower = LONG_MIN;
    return BST2(root, &lower);
}

// @lc code=end

