class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length() < t.length())
            return "";
        
//         a map to hold the freq of chars in pattern
        unordered_map<char,int>m;
        
        int i = 0, j = 0, mn = INT_MAX, ct = 0;
        string ans = "";
        
        for(int i=0;i<t.length();i++)
            m[t[i]]++;
        
//         the ct variable is to keep a check on occurence completion of pattern in a substring
        ct=m.size();
        
        while(j < s.length())
        {
//             if there is a pattern char then reduce its map value and if it becomes zero that means we've got all the char in particular substring, hence reduce count
            if(m.find(s[j]) != m.end())
            {
                m[s[j]]--;
                if(m[s[j]]==0)
                    ct--;
            }

//             if ct is 0, then we need to store the suitable substring into the answer
            if(ct == 0)
            {
                if(mn > j-i+1)
                {
                    mn = j-i+1;
                    ans = s.substr(i, mn);
                }
                
//                 particularly we need to check the posisibility of any smaller previous substring
                while(i <= j && ct == 0)
                {
                    if(m.find(s[i]) != m.end())
                    {
                        m[s[i]]++;
                        
                        if(m[s[i]] > 0)
                        {
                            if(mn > j-i+1)
                            {
                                mn = j-i+1;
                                ans = s.substr(i,mn);
                            }
                            ct++;
                        }
                    }
                    i++;
                }
            }
            j++;
        }
        
        if(mn == INT_MAX)
            return "";
        return ans;
    }
};