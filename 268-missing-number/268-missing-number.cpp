class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans;
        
        for(int i=0;i<nums.size()-1;i++)
            {
                if(nums[i+1]-nums[i]!=1)
                {
                    ans=nums[i]+1;
                    break;
                }
            }
        if(nums[0]!=0)
            ans=0;
        if(nums[nums.size()-1]!=nums.size())
            ans=nums.size();
        return ans;
    }
};