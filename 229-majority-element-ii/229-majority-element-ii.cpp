class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ct = n/3;
        
        unordered_map<int,int>m;
        
        for(int i=0;i<n;i++)
            m[nums[i]]++;
        
        vector<int>ans;
        for(auto x:m)
        {
            if(x.second > ct)
                ans.push_back(x.first);
        }
        
        return ans;
    }
};