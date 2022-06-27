class Solution {
public:
    int climbStairs(int n) {
        long int dp[n+1];
        for(int i=0;i<n+1;i++)
            dp[i] = 0;
        
        dp[0] = 1;
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<=2;j++)
            {
                if(i - j >= 0)
                {
                    dp[i] += dp[i-j];
                }
            }
        }
        return dp[n];
    }
};