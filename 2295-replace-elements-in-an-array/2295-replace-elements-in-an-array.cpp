class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& opr) {
        unordered_map<int,int>m;
        int n = nums.size(), k = opr.size();
        
        for(int i=0;i<n;i++)
            m[nums[i]] = i;
        
        for(int i=0;i<k;i++)
        {
            m[opr[i][1]] = m[opr[i][0]];
            m.erase(opr[i][0]);
        }
        
        for(auto x:m)
        {
            nums[x.second] = x.first;
        }
        
        return nums;
    }
};