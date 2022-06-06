class Solution {
public:
	int lengthOfLongestSubstring(string s) {
       if(s.length() == 0)
           return 0;
        
        int l = 0, r = 0;
        int max=0;
        
        unordered_map<int,int>m;
        while(r<s.length())
        {
            if(m.empty())
            {
                m[s[r]] = r;
            }
            else{
                while(!m.empty() && m.find(s[r])!=m.end())
                {
                    auto it = m.find(s[r]);
                    if((*it).second >= l)
                    l = (*it).second + 1;
                    m.erase(it);
                }
                m[s[r]] = r;
            }
            if(r-l+1>max)
                max = r-l+1;
            r++;
        }
        
        return max;
	}
};