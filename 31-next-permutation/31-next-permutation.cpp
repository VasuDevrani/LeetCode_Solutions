class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int k=n-2,index,c=0;
        while(k>=0)
        {
            if(nums[k]<nums[k+1])
            {
                index=k;
                c++;
                break;
            }
            else
            {
                k--;
            }
        }
        if(c==0){
            sort(nums.begin(),nums.end());
            return;}
            
        int g;
        for(int i=index;i<n;i++)
        {
            if(nums[i]>nums[index] || (nums[i]<g && nums[i]>nums[index]))
                g=i;
        }
        swap(nums[index],nums[g]);
        sort(nums.begin()+index+1,nums.end());
    }
};