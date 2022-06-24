class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int sum = 0;
        sort(nums.begin(), nums.end());
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] >= 0)
            sum += nums[i];
            else
            {
                if(k > 0)
                {
                    sum += abs(nums[i]);
                    nums[i] = abs(nums[i]);
                    k--;
                }
                else
                sum += nums[i];
            }
        }
        
        for(int i=0;i<nums.size();i++)
            cout<<nums[i]<<" ";
        
        if(k%2 == 0)
            return sum;
        else
        {
            return sum - 2*(*min_element(nums.begin(), nums.end()));
        }
    }
};