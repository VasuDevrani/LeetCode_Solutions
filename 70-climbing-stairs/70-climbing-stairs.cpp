class Solution {
public:
    
    int getCount(int n, long int dp[])
    {
//         base case
        if(n == 0)
            return 1;
//         recursive case
        
        if(dp[n] != 0)
            return dp[n];
        
        long int ways = 0;
        for(int i=1;i<=2;i++)
        {
            if(n-i >= 0)
            {
                ways += getCount(n-i, dp);
            }
        }
        return dp[n] = ways;
    }
    
    int climbStairs(int n) {
        long int dp[n+1];
        
        for(int i=0;i<n+1;i++)
            dp[i] = 0;
        
        return getCount(n, dp);
    }
};