/*
 * @lc app=leetcode.cn id=110 lang=c
 *
 * [110] 平衡二叉树
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

int Depth(struct TreeNode* root){
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        int ldepth = Depth(root->left);
        if (ldepth == -1)
            return -1;
        int rdepth = Depth(root->right);
        if (rdepth == -1)
            return -1;
        if (abs(ldepth - rdepth) > 1)
            return -1;
        return 1 + max(ldepth, rdepth);
    }
    
}
bool isBalanced(struct TreeNode* root){
    return Depth(root) != -1;
}
// @lc code=end

