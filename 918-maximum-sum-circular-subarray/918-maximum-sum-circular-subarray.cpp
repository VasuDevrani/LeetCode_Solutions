class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
//      cases: finding max and minsum
        int tot = 0, sum1 = 0, sum2 = 0, mx = INT_MIN, mn = INT_MAX;
        int n = nums.size();
        
        int ct = 0;
        for(int i=0;i<n;i++)
        {
            if(nums[i] >= 0)
                ct++;
        }
        
        for(int i=0;i<n;i++)
        {
            sum1 += nums[i];
            sum2 += nums[i];
            tot += nums[i];
            
            if(sum1 > mx)
                mx = sum1;
            if(sum1 < 0)
                sum1 = 0;
            
            if(sum2 < mn)
                mn = sum2;
            if(sum2 > 0)
                sum2 = 0;
        }
        
        if(ct == 0)
            return mx;
        
        return max(mx, tot-mn);
    }
};