class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>maxims;
        
        for(int i=0;i<nums.size();i++)
        {
            pair<int,int>p;
            p.first=nums[i];
            p.second=i;
            maxims.push(p);
            if(maxims.size()>k)
                maxims.pop();
        }
        
        set<int>s;
        while(!maxims.empty())
        {
            s.insert(maxims.top().second);
            maxims.pop();
        }
        
        vector<int>ans;
        for(auto x:s)
        {
            ans.push_back(nums[x]);
        }
            
        return ans;
    }
};