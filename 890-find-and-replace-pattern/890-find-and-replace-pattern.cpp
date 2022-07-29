class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        unordered_map<char,char>m1, m2;
        int n = words.size();
        
        vector<string>ans;
        for(int i=0;i<n;i++)
        {
            if(words[i].length() < pattern.length())
                continue;
            
            int j = 0, k = 0;
            while(j < pattern.length() && k < pattern.length())
            {
                if(m1.find(words[i][j]) != m1.end() && m1[words[i][j]] != pattern[k])
                {
                    break;
                }else if(m2.find(pattern[k]) != m2.end() && m2[pattern[k]] != words[i][j]){
                    break;
                }
                
                m1[words[i][j]] = pattern[k];
                m2[pattern[k]] =  words[i][j];
                
                j++;
                k++;
            }
            m1.clear();
            m2.clear();
            
            if(j == pattern.length())
                ans.push_back(words[i]);
        }
        
        return ans;
    }
};