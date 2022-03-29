class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max=0;
        for (int i=1;i<nums.size();i++)
        {
            if(nums[i]>nums[max])
                max=i;
        }
        cout<<max<<endl;
        int ct=0;
        for(int i=0;i<nums.size();i++)
        {
            if((nums[i]*2)>nums[max] && i!=max)
            {
                ct++;
            }
        }
        cout<<ct<<endl;
        if(ct==0)
            return max;
        else
        return -1;
    }
};