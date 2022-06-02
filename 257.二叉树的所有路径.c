/*
 * @lc app=leetcode.cn id=257 lang=c
 *
 * [257] 二叉树的所有路径
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

void subTreePaths(struct TreeNode* root, char **subtree, int* path, int depth, int* returnSize)
{
    if (root != NULL)
    {
        path[depth++] = root->val;
        subTreePaths(root->left, subtree, path, depth, returnSize);
        subTreePaths(root->right, subtree, path, depth, returnSize);

        if (root->left == NULL && root->right == NULL)
        {
            char *pathstr = (char*)malloc(sizeof(char) * depth * 6 - 2 + 1);
            sprintf(pathstr, "%d", path[0]);
            for (int i = 1; i < depth; i++)
            {
                sprintf(pathstr, "%s->%d", pathstr, path[i]);
            }
            subtree[*returnSize] = pathstr;
            *returnSize += 1;
        }
    }
}

#define MAXSIZE 100

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** binaryTreePaths(struct TreeNode* root, int* returnSize)
{
    char ** ret = NULL;
    *returnSize = 0;
    if (root != NULL)
    {
        ret = (char**)malloc(sizeof(char*) * MAXSIZE);
        int *path = (char*)malloc(sizeof(int) * MAXSIZE);
        subTreePaths(root, ret, path, 0, returnSize);
        free(path);
    }
    return ret;
}
// @lc code=end

