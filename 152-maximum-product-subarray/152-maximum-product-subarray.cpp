class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        
        int mn = ans, mx = ans;
        for(int i=1;i<n;i++)
        {
            if(nums[i] < 0)
                swap(mn, mx);
            
            mx = max(nums[i], mx*nums[i]);
            mn = min(nums[i], mn*nums[i]);
            
            ans = max(mx, ans);
        }
        
        return ans;
    }
};