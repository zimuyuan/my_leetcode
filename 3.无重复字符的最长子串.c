/*
 * @lc app=leetcode.cn id=3 lang=c
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start


int lengthOfLongestSubstring(char * s){
    char exist[128] = {0};
    int left = 0;
    int right = 0;
    int max_length = 0;
    for (int i = 0; '\0' != s[i]; i++)
    {
        exist[s[right]] += 1;
        if (exist[s[right]] == 1)
        {
            if (max_length < right - left + 1)
            {
                max_length = right - left + 1;
            }
        }
        else
        {
            while (exist[s[right]] > 1)
            {
                exist[s[left++]] -= 1;
            }
        }
        right ++;         
    }

    return max_length;
}
// @lc code=end

