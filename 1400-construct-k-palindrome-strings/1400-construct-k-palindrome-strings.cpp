class Solution {
public:
    bool canConstruct(string s, int k) {
       if(s.length() < k)
           return false;
        
        unordered_map<char,int>m;
        for(char i:s)
            m[i]++;
        
        int ct = 0;
        for(auto x:m)
        {
            if(x.second%2 != 0)
            {
                ct++;
            }
        }
        if(ct > k)
            return false;
        else
            return true;
    }
};