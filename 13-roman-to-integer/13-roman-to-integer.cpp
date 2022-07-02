class Solution {
public:
    int romanToInt(string s) {
        if (s.length() == 0) 
            return 0;
        
        unordered_map<char, int>m = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        
        int ans = 0;
        for (int i = 0; i < s.length() - 1; ++i) 
        {
            if (m[s[i]] < m[s[i + 1]]) 
                ans -= m[s[i]];
            else 
                ans += m[s[i]];
        }
        
        ans += m[s[s.length()-1]];

        return ans;
    }
};