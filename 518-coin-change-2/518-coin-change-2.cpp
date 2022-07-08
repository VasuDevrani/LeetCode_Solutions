class Solution {
public:
    
    int TopBot(int n, int t, vector<int>coins, vector<vector<int>>&dp)
    {
//         base case
        if(n == 0)
        {
            if(t % coins[0] == 0)
                return 1;
            else
                return 0;
        }
//         recursive case
        
        if(dp[n][t] != -1)
            return dp[n][t];
        
        int not_take = TopBot(n-1, t, coins, dp);
        int take = 0;
        
        if(coins[n] <= t)
            take = TopBot(n, t-coins[n], coins, dp);
        
        return dp[n][t] = take + not_take;
    }
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        return TopBot(n-1, amount, coins, dp);
    }
};