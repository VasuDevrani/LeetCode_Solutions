class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        int n = nums.size(), mx = 0;
        vector<int>dp(n, 1), ct(n, 1);
        
        for(int i=0;i<n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(nums[i] > nums[j])
                {
                    if(dp[i] < dp[j] + 1)
                    {
                        dp[i] = dp[j] + 1;
                        ct[i] = ct[j];
                    }
                    else if(dp[i] == dp[j] + 1)
                        ct[i] += ct[j];
                }
            }
        }
        
        int mx_ind = max_element(dp.begin(), dp.end()) - dp.begin();
        
        if(dp[mx_ind] == 1)
            return n;
        
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            if(dp[i] == dp[mx_ind])
                ans += ct[i];
        }
        
        return ans;
    }
};