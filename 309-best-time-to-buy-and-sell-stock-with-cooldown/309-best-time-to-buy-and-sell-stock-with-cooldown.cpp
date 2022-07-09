class Solution {
public:
    
    int profitRecur(vector<int>prices, int n, int i, int buy)
    {
//         base case
        if(i == n)
            return 0;
        
//         recursive case
        
        if(buy == 0){
            return max(profitRecur(prices, n, i+1, buy+1) - prices[i], profitRecur(prices, n, i+1, buy));
        }
        else if(buy == 1){
            return max(profitRecur(prices, n, i+1, buy+1) + prices[i], profitRecur(prices, n, i+1, buy));
        }
        else{
            return profitRecur(prices, n, i+1, 0);
        }
    }
    
    
    int BotUp(vector<int>prices, int n)
    {
        vector<vector<int>>dp(n+1, vector<int>(3, 0));
        
        for(int i=0;i<3;i++)
            dp[n][i] = 0;
        
        for(int i=n-1;i>=0;i--)
        {
            for(int buy=2;buy>=0;buy--)
            {
                if(buy == 0){
                    
                    dp[i][buy] = max(dp[i+1][buy+1] - prices[i], dp[i+1][buy]);
                    
                }
                else if(buy == 1){
                    
                    dp[i][buy] = max(dp[i+1][buy+1] + prices[i], dp[i+1][buy]);
                    
                }
                else{
                    dp[i][buy] = dp[i+1][0];
                }
            }
        }
        
        return dp[0][0];
    }
    
    
    int TopBot(vector<int>prices, int n, int i, int buy, vector<vector<int>>&dp)
    {
//         base case
        if(i == n)
            return 0;
        
//         recursive case
        
        if(dp[i][buy] != -1)
            return dp[i][buy];
        
        if(buy == 0){
            return dp[i][buy] = max(TopBot(prices, n, i+1, buy+1, dp) - prices[i], TopBot(prices, n, i+1, buy, dp));
        }
        else if(buy == 1){
            return dp[i][buy] = max(TopBot(prices, n, i+1, buy+1, dp) + prices[i], TopBot(prices, n, i+1, buy, dp));
        }
        else{
            return dp[i][buy] = TopBot(prices, n, i+1, 0, dp);
        }
    }
    
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        // vector<vector<int>>dp(n, vector<int>(3, -1));
        // return TopBot(prices, n, 0, 0, dp);
        
        return BotUp(prices, n);
    }
};
// 0: buy, 1: sell, 2: calm