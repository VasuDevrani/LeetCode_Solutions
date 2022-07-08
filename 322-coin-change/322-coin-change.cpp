class Solution {
public:
    
    int coinsRecur(int n, int t, vector<int>coins)
    {
//         base case
        if(n == 0)
        {
            if(t % coins[0] == 0)
                return t/coins[0];
            else
                return 100000000;
        }
//         recursive case
        
        int not_take = coinsRecur(n-1, t, coins);
        int take = INT_MAX;
        
        if(coins[n] <= t)
            take = 1 + coinsRecur(n, t-coins[n], coins);
        
        return min(take, not_take);
    }
    
    int TopBot(int n, int t, vector<int>coins, vector<vector<int>>&dp)
    {
//         base case
        if(n == 0)
        {
            if(t % coins[0] == 0)
                return t/coins[0];
            else
                return 100000000;
        }
//         recursive case
        
        if(dp[n][t] != -1)
            return dp[n][t];
        
        int not_take = TopBot(n-1, t, coins, dp);
        int take = INT_MAX;
        
        if(coins[n] <= t)
            take = 1 + TopBot(n, t-coins[n], coins, dp);
        
        return dp[n][t] = min(take, not_take);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        return TopBot(n-1, amount, coins, dp) < 100000000 ? TopBot(n-1, amount, coins, dp) : -1;
    }
};