class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int k = p.length(), i = 0, j = 0;
        vector<int>ans;
        unordered_map<char,int>m;
        
        for(int i=0;i<p.length();i++)
        {
            m[p[i]]++;
        }

        int ct = m.size();
        
        while(j < s.length())
        {
            m[s[j]]--;
            
            if(m[s[j]] == 0)
                ct--;
            if(j-i+1 == k)
            {
                if(ct == 0)
                   ans.push_back(i);
                
                if(m[s[i]] == 0)
                    ct++;
                
                m[s[i]]++;
                i++;
            }
            
            j++;
        }
        return ans;
    }
};