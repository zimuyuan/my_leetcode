/*
 * @lc app=leetcode.cn id=76 lang=c
 *
 * [76] 最小覆盖子串
 */

// @lc code=start


char * minWindow(char * s, char * t){
    int left = 0;
    int right = 0;
    int min_lenght = 0;

    char t_flage[128] = {0};
    char s_flage[128] = {0};
    int t_length = 0;
    int match_length = 0;

    for (int i = 0; t[i] != '\0'; i++)
    {
        t_flage[t[i]] ++;
        if (t_length == 1)
        {
            t_length ++;
        }
    }

    for (int i = 0; s[i] != '\0'; i++)
    {
        s_flage[s[right]]++;
        
        if (s_flage[s[right]] == t_flage[s[right]] && match_length < t_length)
        {
            match_length++;
        }

        while (match_length == t_length)
        {
            if ((t_flage[s[left]] != 0) && ((min_lenght < (right - left + 1)) || (min_lenght == 0)))
            {
                min_lenght = right - left + 1;
            }
            else
            {
                if (t_flage[s[left]] != 0)
                {
                    if (s_flage[s[left]] == t_flage[s[left]])
                    {
                        match_length--;
                    }
                    s_flage[s[left]]--; 
                }
                left++;
            }
        }
        right++;
    }
    
    char * sub_s = (char *)malloc(min_lenght + 1);
    sub_s[min_lenght] = '\0';
    for (int i = 0; i < min_lenght; i++)
    {
        sub_s[i] = s[left + i];
    }
    return sub_s;
}
// @lc code=end

