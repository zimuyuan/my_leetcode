/*
 * @lc app=leetcode.cn id=67 lang=c
 *
 * [67] 二进制求和
 */

// @lc code=start
char * addBinary(char * a, char * b){
    unsigned int a_len = strlen(a);
    unsigned int b_len = strlen(b);
    // 新字符串的空间
    unsigned int sum_len = a_len > b_len ? a_len + 2 : b_len + 2;
    char * sum = (char *)malloc(sum_len);
    sum_len = 0;
    // 保存进位位和两个字符的和
    char carry = 0;

    while (a_len > 0 || b_len > 0 || carry) 
    {
        // 求累加和进位位
        carry += a_len > 0 ? a[--a_len] - '0' : 0;
        carry += b_len > 0 ? b[--b_len] - '0' : 0;
        sum[sum_len++] = (carry & 0x01) + '0';
        carry >>= 1;
    }
    
    // 反转结果字符串
    for (int i = 0; i < sum_len / 2; i++)
    {
        sum[i] ^= sum[sum_len - 1 -i];
        sum[sum_len - 1 -i] ^= sum[i];
        sum[i] ^= sum[sum_len - 1 -i];
    }
    sum[sum_len] = '\0';
    return sum;
}
// @lc code=end
