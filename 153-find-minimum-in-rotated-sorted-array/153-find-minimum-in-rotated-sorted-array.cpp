class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0,h=nums.size()-1;
        if(nums.size()==1)
            return nums[0];
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            
           if(mid==0 || mid==nums.size()-1)
           {
               if(mid==0)
               {
                   if(nums[mid]<nums[mid+1])
                       return nums[mid];
                   else 
                       l=mid+1;
               }
               else if(mid==nums.size()-1)
               {
                   if(nums[mid]<nums[0])
                       return nums[mid];
                   else 
                       h=mid-1;
               }
           }
            else{
            if(nums[mid]<nums[mid+1] && nums[mid]<nums[mid-1])
                return nums[mid];
            else if(nums[mid]>=nums[0] && nums[mid]>nums[h])
                l=mid+1;
            else
                h=mid-1;
           }
        }
        return 0;
    }
};