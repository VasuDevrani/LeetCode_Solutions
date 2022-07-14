class Solution {
public:
    int nthUglyNumber(int n) {
        
        if(n == 1)
            return 1;
        
        int i = 1;
        int dp[n];
        
        dp[0] = 1;
        
        int a = 0, b = 0 , c = 0;
        
        while(i < n)
        {
            dp[i] = min(min(dp[a]*2, dp[b]*3), dp[c]*5);
            if(dp[i] == dp[a]*2)
                a++;
            if(dp[i] == dp[b]*3)
                b++;
            if(dp[i] == dp[c]*5)
                c++;
            
            i++;
        }
        
        return dp[n-1];
    }
};