class Solution {
public:
    
    static bool comp(string a, string b){
        return a.size() < b.size();
    }

    int longestStrChain(vector<string>& words) {
        
        int n = words.size();
        
        sort(words.begin(), words.end(), comp);
        
       unordered_map< string , int> mp;
        int ind = 0;
        for(string a : words)
        {
            for(int i=0;i<a.size();i++)
            {
                string s = a.substr(0 , i) + a.substr(i+1);
                
                if(mp.find(s) == mp.end())
                    mp[a] = max(mp[a] , 1);
                else
                    mp[a] = max(mp[a] , mp[s] +1);
            }
           
        }
        int ans = 0;
        for(auto it=mp.begin();it!=mp.end();it++)
            ans = max ( ans , (*it).second);
        
       return ans; 
    }
};