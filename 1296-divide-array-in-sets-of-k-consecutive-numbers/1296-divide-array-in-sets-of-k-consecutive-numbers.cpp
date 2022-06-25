class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++)
            m[nums[i]]++;
        
        vector<int>v;
        for(auto x:m)
            v.push_back(x.first);
        
        sort(v.begin(), v.end());
        
        for(int i=v.size()-1; i>=k-1; i--)
        {
            while(m.find(v[i]) != m.end())
            {
                int temp = k - 1, check = v[i];
                while(temp--)
                {
                    if(m.find(check - 1) != m.end())
                    {
                        m[check-1]--;
                        if(m[check-1] == 0)
                            m.erase(check-1);
                        check--;
                    }
                    else
                        return false;
                }
                m[v[i]]--;
                if(m[v[i]] == 0)
                    m.erase(v[i]);
            }
        }
        
        if(!m.empty())
            return false;
        return true;
    }
};