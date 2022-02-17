/*
 * @lc app=leetcode.cn id=1 lang=c
 *
 * [1] 两数之和
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int* ret;
    for(int i = 0; i<numsSize; i++)
    {
        for (int j = 0; j < numsSize; j++)
        {
            if((nums[i] + nums[j] == target) && (i != j))
            {
                ret = (int*) malloc(sizeof(int) * 2);
                ret[0] = i;
                ret[1] = j;
                *returnSize = 2;
                return ret;
            }
        }
        
    }
    *returnSize = 0;
    return ret;
}
// @lc code=end

