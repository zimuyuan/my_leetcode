/*
 * @lc app=leetcode.cn id=563 lang=c
 *
 * [563] 二叉树的坡度
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

// 返回此节点的与其左右子树的和,并非计算此节点的坡度
int tilt(struct TreeNode* root, int *sumTile)
{
    // 空节点直接返回零
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        // 递归的到左右节点子树的和
        int left = tilt(root->left, sumTile);
        int right = tilt(root->right, sumTile);
        // 累加该节点的坡度
        *sumTile += abs(left - right);
        // 返回总和
        return root->val + left + right;
    }
}

int findTilt(struct TreeNode* root)
{
    int sumTilt = 0;
    if (root != NULL)
    {
        tilt(root, &sumTilt);
    }
    return sumTilt;
}
// @lc code=end

