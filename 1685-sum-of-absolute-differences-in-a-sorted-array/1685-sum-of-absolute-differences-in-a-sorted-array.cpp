class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int>preSum;
        int n = nums.size(), sum = 0;
        
        for(int i=0;i<n;i++)
        {
            sum += nums[i];
            preSum.push_back(sum);
        }
        
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            int temp = 0;
            temp += (nums[i] * i);
            
            if(i > 0)
                temp -= preSum[i-1];
            
            if(i < n-1)
                temp += preSum[n-1] - preSum[i];
            
            temp -= (nums[i] * (n-i-1));
            
            ans.push_back(temp);
        }
        
        return ans;
    }
};