class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        vector<int>dp(n, 0);
        dp[0] = 1;
        
        for(int i=1;i<n;i++)
        {
            int j = i-1;
            while(j >= 0)
            {
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i], dp[j]);
                }
                j--;
            }
            dp[i]++;
            cout<<dp[i]<<" ";
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};