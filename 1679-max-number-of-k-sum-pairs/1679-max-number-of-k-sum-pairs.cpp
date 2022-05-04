class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        
        long int ct=0;
        int i=0,j=nums.size()-1;
        while(i<j)
        {
            if(nums[i]+nums[j]<k)
                i++;
            else if(nums[i]+nums[j]>k)
                j--;
            else if(nums[i]+nums[j]==k)
            {
                i++;
                j--;
                ct++;
            }     
        }
        return ct;
    }
};