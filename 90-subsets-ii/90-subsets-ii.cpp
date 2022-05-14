class Solution {
public:
    
     void getSubsets(vector<int>nums,vector<vector<int>>&ans)
    {
//         base case
        if(nums.size()==0)
        {
            vector<int>v;
            ans.push_back(v);
            return;
        }
        
//         recursive case
        int a=nums[nums.size()-1];
         nums.pop_back();
         getSubsets(nums,ans);
         
         vector<int>v;
         v.push_back(a);
         
         int n=ans.size();
         for(int i=0;i<n;i++)
         {
             bool flag=true;
             vector<int>t;
             t=ans[i];
             t.push_back(a);
             sort(t.begin(),t.end());
             for(int j=i+1;j<n;j++)
             {
                 if(ans[j]==t)
                     flag=false;
             }
             if(flag==false)
                 continue;
             
             ans.push_back(t);
         }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        
        getSubsets(nums,ans);
        return ans;
    }
};