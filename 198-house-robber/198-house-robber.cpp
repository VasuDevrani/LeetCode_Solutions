class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        if(n == 1)
            return nums[0];
        
        vector<int>dp(n+1, 0);
        dp[0] = 0; //for i<0
        dp[1] = nums[0]; //for i=0
            
        for(int i=1;i<n;i++) //indexes shows the index of nums
        {
//             include case
            int incl = dp[i-1] + nums[i]; //i-1 of nums is i-2 of dp
//             exclude case
            int excl = dp[i];
            
            dp[i+1] = max(incl, excl);
        }
        
        return dp[n];
    }
};