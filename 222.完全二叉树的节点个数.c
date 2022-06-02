/*
 * @lc app=leetcode.cn id=222 lang=c
 *
 * [222] 完全二叉树的节点个数
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

void _countNodes(struct TreeNode* root, int * num)
{
    if (root != NULL)
    {
        *num += 1;
        _countNodes(root->left, num);
        _countNodes(root->right, num);
    }
}

void _leftDepths(struct TreeNode* root, int * int depth)
{
    if (root != NULL)
    {
        *depth += 1;
        _leftDepths(root->left, depth);
    }
}

int _rightDepths(struct TreeNode* root, int * int depth)
{
    if (root != NULL)
    {
        *depth += 1;
        if (root->left)
        {
            _rightDepths(root->left, depth);
        }
        else
        {
            if (root->right)
            {
                *depth += 1;
                return 0;
            }
        }
    }
    return 1;
}

int countNodes(struct TreeNode* root)
{
    int num = 0;
    _countNodes(root, &num);
    return num;
}
// @lc code=end

