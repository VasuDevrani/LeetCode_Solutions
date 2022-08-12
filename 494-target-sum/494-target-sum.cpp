class Solution {
public:
    
    int ansRecur(vector<int>nums, int t, int sum, int i, vector<vector<int>>&dp)
    {
//         base case
        if(i < 0)
        {
            if(sum == t)
                return 1;
            else
                return 0;
        }
//         recurisve case
        if(dp[i][sum] != -1)
            return dp[i][sum];
        
        int not_take = ansRecur(nums, t, sum, i-1, dp);
        int take = ansRecur(nums, t, sum + nums[i], i-1, dp);
        
        return dp[i][sum] = take + not_take;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
//         we simply need to find a subset with sum equal to (target + sum(nums))/2;
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        
        int newTarget = (target + sum)/2;
        if((target + sum) % 2 != 0)
            return 0;
        
        vector<vector<int>>dp(n, vector<int>(sum + 1, -1));
        return ansRecur(nums, newTarget, 0, n-1, dp);
    }
};