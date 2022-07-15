class Solution {
public:
      
    int ansRecur(vector<int>nums, int t, int n)
    {
//         base case
        if(t == 0)
            return 1;
        
//         recursive case
        
        int ways = 0;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i] <= t)
                ways += ansRecur(nums, t-nums[i], n);
        }
        return ways;
    }
    
    int TopDown(vector<int>nums, int t, int n, vector<int>&dp)
    {
//         base case
        if(t == 0)
            return 1;
        
//         recursive case
        if(dp[t] != -1)
            return dp[t];
        
        int ways = 0;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i] <= t)
                ways += ansRecur(nums, t-nums[i], n);
        }
        return dp[t] = ways;
    }
    
    
    int BotTop(vector<int>nums, int t, int n)
    {
        vector<double>dp(t+1, 0);
        
        dp[0] = 1;
        
        for(int i=1;i<=t;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(nums[j] <= i)
                    dp[i] += dp[i-nums[j]];
            }
        }
        
        return dp[t];
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        
        // return ansRecur(nums, target, n);
        
        // vector<int>dp(target+1, -1);
        // return TopDown(nums, target, n,  dp);
        
        return BotTop(nums, target, n);
    }
};