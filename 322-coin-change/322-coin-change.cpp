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
    
    int BotTop(int n, int t, vector<int>coins)
    {
        vector<vector<int>>dp(n, vector<int>(t+1, 0));
        
        for(int target=0; target<=t; target++)
        {
            if(target % coins[0] == 0)
                dp[0][target] = target / coins[0];
            else
                dp[0][target] = 100000000;
        }
        
        for(int i=1;i<n;i++) //index
        {
            for(int j=0;j<=t;j++)
            {
                int not_take = dp[i-1][j];
                int take = INT_MAX;

                if(coins[i] <= j)
                    take = 1 + dp[i][j-coins[i]];

                dp[i][j] = min(take, not_take);
            }
        }
        
        return dp[n-1][t] < 100000000 ? dp[n-1][t] : -1;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0)
            return 0;
        int n = coins.size();
        
        // vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        // return TopBot(n-1, amount, coins, dp) < 100000000 ? TopBot(n-1, amount, coins, dp) : -1;
        return BotTop(n, amount, coins);
    }
};