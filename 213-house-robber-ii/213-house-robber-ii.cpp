class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 0)
            return 0;
        if(n == 1)
            return nums[0];
        if(n == 2)
            return max(nums[0], nums[1]);
        
        vector<int>dp1(n, 0);
        vector<int>dp2(n, 0);
        
        dp1[0] = 0;
        dp1[1] = nums[0];
        
        for(int i=1;i<n-1;i++)
        {
            int incl = dp1[i-1] + nums[i];
            int excl = dp1[i];
            
            dp1[i+1] = max(incl, excl);
        }
        
        dp2[0] = 0;
        dp2[1] = nums[1];
        
        for(int i=2;i<n;i++)
        {
            int incl = dp2[i-2] + nums[i];
            int excl = dp2[i-1];
            
            dp2[i] = max(incl, excl);
        }
        
        return max(dp1[n-1], dp2[n-1]);
    }
};