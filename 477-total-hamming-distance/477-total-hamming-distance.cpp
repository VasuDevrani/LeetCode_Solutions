class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        
        int ans=0;
        for(int i=0;i<32;i++)
        {
            int one=0,zero=0;
            for(int j=0;j<nums.size();j++)
            {
                if((nums[j]&1)!=0)
                    one++;
                else
                    zero++;
                nums[j]=nums[j]>>1;
            }
            ans+=(one*zero);
        }
        return ans; 
        
//         Below solution is with time complexity O(n^2);
        
        // long int sum=0;
        // for(int i=0;i<nums.size()-1;i++)
        // {
        //     for(int j=i+1;j<nums.size();j++)
        //     { int temp=nums[i];
        //          temp^=nums[j];
        //         int count=0;
        //         while(temp>0){
        //             temp&=(temp-1);
        //             count++;
        //         }
        //         sum+=count;
        //     }
        // }
        // return sum;
    }
};