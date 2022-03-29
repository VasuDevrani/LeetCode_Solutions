class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ct=0;
        int sum=0;
        int min=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            if(min>nums[i])
                min=nums[i];
        }
        for(int i=0;i<nums.size();i++)
        {
           if(nums[i]!=min)
           {
               if(nums[i]>nums[i-1])
               {
                   ct++;
                   sum=sum+ct;
               }
               else if(nums[i]=nums[i-1])
               {
                   sum=sum+ct;
               }
           }
        }
        return sum;
        
        
        
        
        
        
//         TLE solution
        // int sum=0;
        // for(int i=nums.size()-1;i>=1;i--)
        // {
        //     int temp=nums[i];
        //     for(int j=i-1;j>=0;j--)
        //     {
        //         if(temp>nums[j])
        //         {
        //             temp=nums[j];
        //             sum++;
        //         }
        //     }
        // }
        // return sum;
    }
};