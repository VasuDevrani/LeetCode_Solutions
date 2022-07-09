class Solution {
public:
    
    int BotTop_space(vector<int>prices, int n, int fee)
    {
        int pb = 0, ps = 0;
        
        for(int i=n-1;i>=0;i--) //index
        {
            for(int buy=0;buy<=1;buy++)
            {
                if(buy == 1){
                    int buyIt = ps - prices[i];
                    int notBuy = pb;

                    pb = max(buyIt, notBuy);
                }
                else{
                    int sellIt = pb + prices[i] - fee;
                    int notSell = ps;

                    ps = max(sellIt, notSell);
                }
            }
        }
        
        return pb;
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        
        return BotTop_space(prices, prices.size(), fee);
    }
};