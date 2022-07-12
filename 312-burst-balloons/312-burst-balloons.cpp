class Solution {
public:
    
    int ansRecur(vector<int>nums, int i, int j, vector<vector<int>>&dp)
    {
//         base case
        if(i > j)
            return 0;
        
//         recursive case
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int coins = INT_MIN;
        for(int k=i;k<=j;k++)
        {
            int temp;
            temp = nums[i-1]*nums[k]*nums[j+1] + ansRecur(nums, k+1, j, dp) + ansRecur(nums, i, k-1, dp);
            
            coins = max(coins, temp);
        }
        
        return dp[i][j] = coins;
    }
    
    int BotUp(vector<int>nums, int n)
    {
        vector<vector<int>>dp(n, vector<int>(n, 0));
        
        for(int i=n-2;i>=1;i--)
        {
            for(int j=i;j<n-1;j++)
            {
                int coins = INT_MIN;
                for(int k=i;k<=j;k++)
                {
                    int temp;
                    temp = nums[i-1]*nums[k]*nums[j+1] + dp[k+1][j] + dp[i][k-1];

                    coins = max(coins, temp);
                }

                dp[i][j] = coins;
            }
        }
        
        return dp[1][n-2];
    }
    
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        
        int n = nums.size();
        
        // vector<vector<int>>dp(n, vector<int>(n, -1));
        // return ansRecur(nums, 1, n-2, dp);
        
        return BotUp(nums, n);
    }
};