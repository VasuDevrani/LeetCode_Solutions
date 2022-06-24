class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int i = 0, j = 0, ct = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        while(j < s.size() && i < g.size())
        {
            if(g[i] <= s[j])
            {
                i++;
                j++;
                ct++;
            }
            else
                j++;
        }
        
        return ct;
    }
};