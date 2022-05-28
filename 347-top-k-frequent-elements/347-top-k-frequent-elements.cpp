class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        if(nums.size()==1)
            return nums;
        sort(nums.begin(),nums.end());
        priority_queue<pair<int,int>>q;
        
        int ct=1;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]==nums[i+1])
                ct++;
            else
            {
                q.push(make_pair(ct,i));
                ct=1;
            }
        }
        if(ct!=1)
        {
            q.push(make_pair(ct,nums.size()-1));
        }
        if(nums.size()>1 && nums[nums.size()-1]!=nums[nums.size()-2])
            q.push(make_pair(1,nums.size()-1));
        
        ct=1;
        vector<int>ans;
        // cout<<q.size()<<nums[q.top().second]<<endl;
        while(!q.empty() && ct<=k)
        {
            ans.push_back(nums[q.top().second]);
            q.pop();
            ct++;
        }
        return ans;
    }
};