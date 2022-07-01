class Solution {
public:
    
    int getAns(vector<int>nums, int i, int dp[])
    {
//         base case
        if(i >= nums.size())
            return 0;
        
//         recursive case
        if(dp[i] != -1)
            return dp[i];
        
        int mx = 0;
        int j = i+2;
        
        while(1)
        {
            int sum = nums[i] + getAns(nums, j, dp);
            cout<<sum<<" ";
            mx = max(sum, mx);
            if(j >= nums.size())
                break;
            j++;
        }
        
        return dp[i] = mx;
    }
    
    int rob(vector<int>& nums) {
        
        if(nums.size() == 1)
            return nums[0];
        
        int mx = 0;
        int dp[nums.size()];
        
        for(int i=0;i<nums.size();i++)
            dp[i] = -1;
    
        mx = max(getAns(nums, 0, dp), getAns(nums, 1, dp));
        
        return mx;
    }
};