class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
//         in actual the problem can be soved in O(1) using XOR
        
//         Using binary search
        if(nums.size()==1)
        {
            return nums[0];
        }
        int l=0,h=nums.size()-1;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if((mid%2)==0)
            {
               if(nums[mid]==nums[mid+1])
                   l=mid+1;
                else
                    h=mid-1;
            }
           else
            {
               if(nums[mid]==nums[mid-1])
                   l=mid+1;
                else
                    h=mid-1;
            }
        }
        return nums[l];
    }
};