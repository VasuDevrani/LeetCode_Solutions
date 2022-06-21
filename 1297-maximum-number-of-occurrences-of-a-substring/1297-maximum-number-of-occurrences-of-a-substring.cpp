class Solution {
public:
    int maxFreq(string s, int k, int minSize, int maxSize) {
//      for the solution part we just need to consider the miSize and it'd have the max                   occurences
        
        int i = 0, j = 0;
        unordered_map<char,int>m;
        unordered_map<string,int>ans;
        
        while(j <= s.length())
        {
            if(j-i == minSize)
            {
                if(m.size() <= k)
                {
                    string temp = s.substr(i, j-i);
                    cout<<temp<<" ";
                    ans[temp]++;
                }
                m[s[i]]--;
                if(m[s[i]] == 0)
                    m.erase(s[i]);
                i++;
            }
            m[s[j]]++;
            j++;
        }
        
        int max = 0;
        for(auto x:ans)
        {
            if(x.second > max)
                max = x.second;
        }
        
        return max;
    }
};