class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>>ans;
        if(nums.size()<4)
            return ans;
        
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-3;i++)
        {
            for(int j=i+1;j<nums.size()-2;j++)
            {
                int left = target-nums[i]-nums[j];
                int k=j+1,l=nums.size()-1;
                while(k<l)
                {
                     if(nums[k]+nums[l]==left)
                     {
                         vector<int>v{nums[i],nums[j],nums[k],nums[l]};
                         if(ans.empty())
                         ans.push_back(v);
                         else
                         {
                             int ct=0;
                             for(int i=0;i<ans.size();i++)
                             {
                                 if(ans[i]==v)
                                 {
                                     ct++;
                                     break;
                                 }
                             }
                             if(ct==0)
                                 ans.push_back(v);
                         }
                         k++;
                         l--;
                     }
                    else if(nums[k]+nums[l]<left)
                        k++;
                    else
                        l--;
                }
            }
        }
        
        return ans;
    }
};