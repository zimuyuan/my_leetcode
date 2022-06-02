/*
 * @lc app=leetcode.cn id=572 lang=c
 *
 * [572] 另一棵树的子树
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

bool subtree(struct TreeNode* root, struct TreeNode* subRoot)
{
    // 子树节点比较完毕
    if(root == NULL || subRoot == NULL)
    {
        // 同时为空则满足
        return (root == subRoot);
    }
    else
    {
        return root->val == subRoot->val \
            && subtree(root->left, subRoot->left) \
            && subtree(root->right, subRoot->right);
    }
}

bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot)
{
    return subtree(root, subRoot);
}
// @lc code=end

