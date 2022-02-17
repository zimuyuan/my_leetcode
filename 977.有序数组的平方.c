/*
 * @lc app=leetcode.cn id=977 lang=c
 *
 * [977] 有序数组的平方
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize){
    int * sort_nums = malloc(sizeof(int) * numsSize);
    int end = numsSize - 1;
    int start = 0;
    *returnSize = numsSize;
    for (int i = numsSize - 1; i >= 0; i--)
    {
        if (nums[start] * nums[start] > nums[end] * nums[end])
        {
            sort_nums[i] = nums[start] * nums[start];
            start ++;
        }
        else
        {
            sort_nums[i] = nums[end] * nums[end];
            end --;
        }
    }
    return sort_nums;
}
// @lc code=end

