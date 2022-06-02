/*
 * @lc app=leetcode.cn id=107 lang=c
 *
 * [107] 二叉树的层序遍历 II
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


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MAXSIZE 2000

int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes){

    int ** ret = NULL;
    *returnSize = 0;
    if (root == NULL)
    {
        return NULL;
    }
    
    // queue 用于保存所以节点指针
    struct TreeNode *queue[MAXSIZE];
    ret = malloc(sizeof(int *) * MAXSIZE);
    *returnColumnSizes = malloc(sizeof(int *) * MAXSIZE);

    // rear front 用于记录数组中未保存的节点指针
    int rear = 0;
    int front = 0;

    // 存入根节点,并开始向下逐层搜索
    queue[rear++] = root;

    while (front < rear)
    {
        // 当前层节点数
        (*returnColumnSizes)[*returnSize] = rear - front;
        // 申请空间保存节点
        int *retCol = malloc(sizeof(int) * (*returnColumnSizes)[*returnSize]);
        // 当前层逐个保存
        for (int i = 0; i < (*returnColumnSizes)[*returnSize]; i++)
        {
            // 取出节点，front 也对应后移
            struct TreeNode *p = queue[front++];
            if(p != NULL)
                retCol[i] = p->val;
            // 如果存在子节点,则保存相应子节点，rear 也对应后移
            if(p->left != NULL)
                queue[rear++] = p->left;
            if(p->right != NULL)
                queue[rear++] = p->right;
        }
        // 记录此层,用于返回
        ret[(*returnSize)++] = retCol;
    }

    // 上下层翻转
    for (int i = 0; i < *returnSize / 2; i++)
    {
        int *top = ret[i];
        ret[i] = ret[*returnSize - i - 1];
        ret[*returnSize - i - 1] = top;

        int topSize = (*returnColumnSizes)[i];
        (*returnColumnSizes)[i] = (*returnColumnSizes)[*returnSize - i - 1];
        (*returnColumnSizes)[*returnSize - i - 1] = topSize;
    }
    return ret;
}
// @lc code=end

