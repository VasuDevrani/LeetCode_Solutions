class Solution {
public:
    int maxNumberOfBalloons(string s) {
        if(s.length() < 7)
            return 0;
        string t = "balloon";
        unordered_map<char,int>m;
        
        for(int i=0;i<s.length();i++)
        {
            if(t.find(s[i]) != string::npos)
                m[s[i]]++;
        }
        
        if(m.size() < 5)
            return 0;
        
        int mn = INT_MAX;
        for(auto x:m)
        {
            if(x.first == 'l' || x.first == 'o')
                mn = min(mn, x.second/2);
            else
                mn = min(mn, x.second);
        }
        
        return mn;
    }
};