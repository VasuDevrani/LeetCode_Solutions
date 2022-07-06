class Solution {
public:
//     dry run here: -2,2,4,3,0,1,-2,-1
    
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        
        int mn = ans, mx = ans;
        for(int i=1;i<n;i++)
        {
//             whenever there's a negative element, it is gonna reduce the max and increase the small, so swap them...
            if(nums[i] < 0)
                swap(mn, mx);
            
//             this operation ensures the regeneration of product if 0 has arrived
            mx = max(nums[i], mx*nums[i]);
            mn = min(nums[i], mn*nums[i]);
            
            ans = max(mx, ans);
        }
        
        return ans;
    }
};