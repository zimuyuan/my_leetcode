/*
 * @lc app=leetcode.cn id=1022 lang=c
 *
 * [1022] 从根到叶的二进制数之和
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

void everySumRootToLeaf(struct TreeNode* root, int *sum, int current)
{
    if (root != NULL)
    {
        // 保存从根节点至该节点的二进制 01 串表示的数
        current = (current << 1) | root->val;

        // 从左右子节点向下搜索
        everySumRootToLeaf(root->left, sum, current);
        everySumRootToLeaf(root->right, sum, current);

        // 当前节没有子节点，则把次 01 串累加到最后结果
        if (root->left == NULL && root->right == NULL)
        {
            return *sum += current;
        }
    }
}

int sumRootToLeaf(struct TreeNode* root){
    int sum = 0;
    int current = 0;
    if (root != NULL)
    {
        everySumRootToLeaf(root, &sum, current);
    }
    return sum;
}
// @lc code=end

