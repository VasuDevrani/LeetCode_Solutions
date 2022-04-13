class Solution {
public:
    void combin_sum(vector<int>main,int t,int i,vector<vector<int>>&ans,vector<int>temp)
    {
//         base case
        if(t==0)
        {
            ans.push_back(temp);
            return;
        }
        if(i>=main.size() || t<0)
            return;
        
//         recursive case
        for(int j=i;j<main.size();j++)
        {
               if(j>i && main[j]==main[j-1])
                continue;
            temp.push_back(main[j]);
            combin_sum(main,t-main[j],j+1,ans,temp);
            temp.pop_back();
        }  
    } 
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        sort(candidates.begin(),candidates.end());
        combin_sum(candidates,target,0,ans,temp);
        return ans;
    }
};