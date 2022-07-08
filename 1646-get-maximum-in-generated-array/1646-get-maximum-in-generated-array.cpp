class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n == 0 || n == 1)
            return n;
        
        vector<int>nums(n+1, 0);
        
        nums[0] = 0;
        nums[1] = 1;
        
        int mx = 1;
        for(int i=2;i<n+1;i++)
        {
            if(i&1)
            {
                int j = (i-1)/2;
                nums[i] = nums[j] + nums[j+1];
            }
            else{
                nums[i] = nums[i/2];
            }
            if(nums[i] > mx)
                mx = nums[i];
        }
        return mx;
    }
};