class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int>s;
        
        int i = 0, j = 0, n = nums.size();
        int ans = INT_MIN, diff = 0;
        
        while(j < n)
        {
            s.insert(nums[j]);
            diff = *s.rbegin() - *s.begin();

            if(diff <= limit)
            {
                ans = max(ans, j-i+1);
                j++;
                continue;
            }
            
            while(*s.rbegin()-*s.begin() > limit)
            {
                s.erase(s.find(nums[i]));
                i++;
                diff = *s.rbegin()-*s.begin();
            }
            j++;
        }
        return ans;
        
    }
};