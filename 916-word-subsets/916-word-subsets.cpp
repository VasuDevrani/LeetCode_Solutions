class Solution {
public:
    vector<string> wordSubsets(vector<string>& word1, vector<string>& word2) {
        unordered_map<char,int>main;
        
        int n = word1.size(), m = word2.size();
        
        for(int i=0;i<m;i++)
        {
            unordered_map<char, int>temp;
            
            for(int j=0;j<word2[i].length();j++){
               temp[word2[i][j]]++;
                main[word2[i][j]] = max(main[word2[i][j]], temp[word2[i][j]]);
            }
        }
        
        // for(auto x:main)
        //     cout<<x.first<<" "<<x.second<<endl;
        
        vector<string>ans;
        for(int i=0;i<n;i++)
        {
            unordered_map<char, int>mp;
            for(int j=0;j<word1[i].length();j++)
                mp[word1[i][j]]++;
            
            bool check = true;
            for(auto x:main)
            {
                if(x.second > mp[x.first])
                    check = false;
            }
            if(check)
                ans.push_back(word1[i]);
        }
        
        return ans;
    }
};