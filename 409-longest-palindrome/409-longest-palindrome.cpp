class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>m;
        
        for(int i=0;i<s.length();i++)
            m[s[i]]++;
        
        int ans = 0, ct = 0;
        for(auto x:m)
        {
            ans += ((x.second/2)*2);
            if(x.second%2 != 0)
                ct++;
        }
        
        return ct > 0 ? ans+1 : ans;
    }
};