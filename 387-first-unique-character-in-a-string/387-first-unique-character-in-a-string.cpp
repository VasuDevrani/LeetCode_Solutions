class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, pair<int,int>>m;
        
        for(int i=s.length()-1;i>=0;i--)
        {
            if(m.find(s[i]) == m.end())
                m[s[i]] = make_pair(i, 1);
            else
                m[s[i]].second++;
        }
        
        for(auto ch: m)
        {
            if(ch.second.second == 1)
                return ch.second.first;
        }
        return -1;
    }
};