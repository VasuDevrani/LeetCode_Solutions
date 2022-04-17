class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        vector<int>ans;
//         get the xor of two non repeated numbers
        int xr=nums[0];
     for(int i=1;i<nums.size();i++)
     {
         xr^=nums[i];
     }
        
//         find the first '1' in binary of xor
        int check=xr;
        int i=0;
        while((check&1)!=1)
        {
            i++;
            check=check>>1;
        }
      
//      find one of the number
        int sum=0;
        for(int j=0;j<nums.size();j++)
        {
            int temp=nums[j];
            nums[j]=nums[j]>>i;
            if((nums[j]&1)==1)
            sum^=temp;
             
        }
      
        ans.push_back(sum);
        ans.push_back(sum^xr);
        
        return ans;
        
    }
};