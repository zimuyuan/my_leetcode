/*
 * @lc app=leetcode.cn id=99 lang=c
 *
 * [99] 恢复二叉搜索树
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

void BSTTree(struct TreeNode* root, long long *pre, int **val, int *num)
{
    if (root != NULL)
    {
        BSTTree(root->left, pre, val, num);
        printf("pp %lld\n", *pre);
        printf("val %d\n", root->val);
        if (root->val <= *pre)
        {
            val[*num++] = &(root->val);
            if (num >= 2)
                return;
        }
      
        *pre = root->val;
        
        BSTTree(root->right, pre, val, num);
    }

}
void recoverTree(struct TreeNode* root)
{
    int *val[2];
    int num = 0;
    long long pre = LONG_MIN;
    BSTTree(root, &pre, val, &num);
    int  c = *(val[0]);
    *(val[0]) = *(val[1]);
    *(val[1]) = c;
}
// @lc code=end

