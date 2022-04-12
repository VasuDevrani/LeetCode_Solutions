class Solution {
public:
    int thirdMax(vector<int>& nums) {

        long int max1=INT_MIN,max2=INT_MIN,max3=INT_MIN;
            for(int i=0;i<nums.size();i++)
            {
                if(nums[i]>=max1)
                    max1=nums[i];
            }
           
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>=max2 && nums[i]!=max1)
                max2=nums[i];
        }
        int k=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>=max3 && nums[i]!=max1 && nums[i]!=max2)
            { max3=nums[i];
             k++;
            }
        }
        if(k>0)
            return max3;
        else 
            return max1;
        
    }
};