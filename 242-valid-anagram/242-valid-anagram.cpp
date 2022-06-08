class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())
            return false;
        
        unordered_map<char,int>m;
        
        for(auto i:s)
            m[i]++;
        for(auto i:t)
            m[i]--;
        
        for(auto x:m)
        {
            if(x.second!=0)
                return false;
        }
        
        return true;
    }
};