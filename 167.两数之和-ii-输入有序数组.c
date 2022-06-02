/*
 * @lc app=leetcode.cn id=167 lang=c
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int front;
    int rear;
    int mid;
    int subTarget;
    int * ret = malloc(sizeof(int) * 2);
    *returnSize = 0;
    for (int i = 0; i < numbersSize; i ++)
    {
        // 转化目标 target
        subTarget = target - numbers[i];
        front = i + 1;
        rear = numbersSize - 1;
        ret[0] = i + 1;
        // 目标小于最小，或大于最大则直接下一轮
        if (subTarget < numbers[front] || subTarget > numbers[rear])
            continue;
        
        // 利用二分查找法,查找对应的目标
        while (front <= rear)
        {    
            mid = (rear + front) / 2;
            if (subTarget > numbers[mid])
            {
                front = mid + 1;
            }
            else if (subTarget < numbers[mid])
            {
                rear = mid - 1;
            }
            else
            {
                ret[1] = mid + 1;
                *returnSize = 2;
                return ret;
            }
        }
    }
    return ret;
}
// @lc code=end

