/*
 * @lc app=leetcode.cn id=263 lang=c
 *
 * [263] 丑数
 */

// @lc code=start


bool isUgly(int n)
{
    while (n)
    {
        if (n % 2 == 0)
        {
            n /= 2;
            continue;
        }
        if (n % 3 == 0)
        {
            n /= 3;
            continue;
        }
        if (n % 5 == 0)
        {
            n /= 5;
            continue;
        }
        break;
    }
    
    return n == 1;
}
// @lc code=end

