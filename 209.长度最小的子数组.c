/*
 * @lc app=leetcode.cn id=209 lang=c
 *
 * [209] 长度最小的子数组
 */

// @lc code=start


int minSubArrayLen(int target, int* nums, int numsSize){
    int left = 0;
    int right = 0;
    int sum = 0;
    int min_lenth = 0;
    for (int i = 0; i < numsSize; i++)
    {
        sum += nums[right];

        while ( sum >= target)
        {
            if (min_lenth  == 0 || min_lenth > right - left + 1)
            {
                min_lenth = right - left + 1;
            }
           sum -= nums[left++];
        }

        right ++;
    }
    return min_lenth;
}
// @lc code=end

