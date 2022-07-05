class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        
        map<vector<int>,vector<string>> m;
        
        for(auto word : strs)
        {
            vector<int> ct(26);      
            for(auto ch : word){
                ct[ch - 'a'] += 1;  
            } 
            m[ct].push_back(word);
        }
        for(auto it : m){
            ans.push_back(it.second); 
        }
            
        return ans;
    }
};