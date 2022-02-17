int climbStairs(int n)
{

    int sum = 1;
    int dp[2] = {1,1};
    for (int i=2; i<=n; i++)
    {
        sum = dp[0] + dp [1];
        dp[0] = dp[1];
        dp[1] = sum;
    }
    return sum;
    
}