class Solution {
public:
    int minSubArrayLen(int k, vector<int>& nums) {
        int i = 0, j = 0, ans = nums.size(), sum = 0, ct = 0;
        
        while(j < nums.size())
        {
            sum += nums[j];
            if(sum >= k)
            {
                ct++;
                ans = min(ans, j-i+1);
                while(sum > k)
                {
                    sum -= nums[i];
                    i++;
                    if(sum >= k)
                        ans = min(ans, j-i+1);
                }
            }
            j++;
        }
        
        if(ct > 0)
            return ans;
        else
            return 0;
    }
};