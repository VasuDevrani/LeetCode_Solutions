class Solution {
public:
    
    void getPermute(vector<int>nums,vector<vector<int>>&ans,vector<int>&temp)
    {
//         base case
        if(nums.size()==0)
        {
            ans.push_back(temp);
            return;
        }
        
//         recursive case
        for(int i=0;i<nums.size();i++)
        {
            bool flag=false;
            
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[j]==nums[i])
                    flag=true;
            }
            if(flag==false){
            temp.push_back(nums[i]);
            vector<int>nums1=nums;
            nums1.erase(nums1.begin()+i);
            getPermute(nums1,ans,temp);
            temp.pop_back();
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        getPermute(nums,ans,temp);
        
        return ans;
    }
};
    
 