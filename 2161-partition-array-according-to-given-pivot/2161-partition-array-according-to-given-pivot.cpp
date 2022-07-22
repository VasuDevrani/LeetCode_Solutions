class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int low = 0, same = 0, high;
        for (auto x : nums)
        {
            if (x < pivot)
                ++low;
            else if (x == pivot)
                ++same;
        }
        
        vector<int>ans(nums.size());
        high = same + low;
        same = low;
        low = 0;
        
        for (auto x : nums)
        {
            if (x < pivot)
                ans[low++] = x;
            else if (x == pivot)
                ans[same++] = x;
            else
                ans[high++] = x;
        }
        return ans;
    }
};