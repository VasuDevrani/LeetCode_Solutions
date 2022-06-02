class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        if(nums.size()==1)
            return 1;
        
        unordered_map<int,int>m;
        
        for(int i=0;i<nums.size();i++)
        {
            m.insert(make_pair(nums[i],i));
        }
        
        int max=INT_MIN;
        for(auto it=m.begin();it!=m.end();it++)
        {
            int n=(*it).first;
            int ct=1;
            if(m.find(n-1)!=m.end())
                continue;
            while(m.find(n+1)!=m.end())
            {
                ct++;
                n=n+1;
            }
            if(ct>max)
                max=ct;
        }
        
        return max;
    }
};