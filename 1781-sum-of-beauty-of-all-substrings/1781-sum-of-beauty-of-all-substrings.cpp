class Solution {
public:
    
//     simple soultion +> generate substring and calculate the beauty using map and accumulate them
    int beautySum(string s) {
        unordered_map<char, int> m;
        int ct = 0;
        
        for (int i = 0; i < s.size(); i++)
        {
            m.clear();
            for (int j = i; j < s.size(); j++)
            {
                m[s[j]]++;
                int mx = INT_MIN;
                int mn = INT_MAX;
                for (auto x: m)
                {
                    mx = max(mx, x.second);
                    mn = min(mn, x.second);
                }
                ct += mx - mn;
            }
        }
        return ct;
    }
};