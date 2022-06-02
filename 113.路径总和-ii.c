/*
 * @lc app=leetcode.cn id=113 lang=c
 *
 * [113] 路径总和 II
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
// 辅助函数 path 用于记录节点值,depth 记录深度,也是路径的长度, trageSum 目标和
void subTreePaths(struct TreeNode* root, int **ret, int* path, int depth, int targetSum, int* returnSize, int** returnColumnSizes)
{
    if (root != NULL)
    {
        // 缓存节点值
        path[depth++] = root->val;

        // 向下搜索
        subTreePaths(root->left, ret, path, depth, targetSum - root->val, returnSize, returnColumnSizes);
        subTreePaths(root->right, ret, path, depth, targetSum - root->val, returnSize, returnColumnSizes);
        
        // 找到叶子节点, 判断是否满足路径之和等于 targeSum
        if (root->left == NULL && root->right == NULL && root->val == targetSum)
        {
            // 保存路径节点到,对应的返回指针中
            // 申请保存此路径的内存空间
            int *targePath = malloc(sizeof(int) * depth);
            for (int i = 0; i < depth; i++)
            {
                targePath[i] = path[i];
            }
            (*returnColumnSizes)[*returnSize] = depth;
            ret[*returnSize] = targePath;
            (*returnSize)++;
        }
    }
}


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#define MAXSIZE 1000

int** pathSum(struct TreeNode* root, int targetSum, int* returnSize, int** returnColumnSizes)
{
    int ** ret = NULL;
    *returnSize = 0;
    if (root != NULL)
    {
        ret = (int**)malloc(sizeof(int*) * MAXSIZE);
        *returnColumnSizes = (int *)malloc(sizeof(int) * MAXSIZE);
        // path 用来记录缓存搜索路径中的节点值
        int *path = (char*)malloc(sizeof(int) * MAXSIZE);
        subTreePaths(root, ret, path, 0, targetSum, returnSize, returnColumnSizes);
        free(path);
    }
    return ret;
}
// @lc code=end

