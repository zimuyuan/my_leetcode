/*
 * @lc app=leetcode.cn id=637 lang=c
 *
 * [637] 二叉树的层平均值
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
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define MAXSIZE 10000

double* averageOfLevels(struct TreeNode* root, int* returnSize)
{
    
    double *ret = NULL;
    *returnSize = 0;

    if (root == NULL)
    {
        return NULL;
    }
    
    // queue 用于保存所以节点指针
    struct TreeNode *queue[MAXSIZE];
    ret = malloc(sizeof(double) * MAXSIZE);
    int colSize = 0;
    double colSum = 0.;
    // rear front 用于记录数组中未保存的节点指针
    int rear = 0;
    int front = 0;

    // 存入根节点,并开始向下逐层搜索
    queue[rear++] = root;

    while (front < rear)
    {
        // 当前层节点数
        colSize = rear - front;
        colSum = 0.;

        // 当前层逐个节点处理
        for (int i = 0; i < colSize; i++)
        {
            // 取出节点，front 也对应后移
            struct TreeNode *p = queue[front++];
            if (p != NULL)
            {
                // 当前层节点值累加
                colSum += p->val;
            }
            // 如果存在子节点,则保存相应子节点，rear 也对应后移
            if(p->left != NULL)
                queue[rear++] = p->left;
            if(p->right != NULL)
                queue[rear++] = p->right;
        }
        // 记录此层平均值
        ret[(*returnSize)++] = colSum / colSize;
    }
    return ret;
}
// @lc code=end

