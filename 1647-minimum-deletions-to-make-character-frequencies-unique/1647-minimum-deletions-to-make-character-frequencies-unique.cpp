class Solution {
public:
    int minDeletions(string s) {
        if(s.length() == 1)
            return 0;
        
        sort(s.begin(),s.end());
        
        vector<int>freq(26,0);
        int ans = 0;
        unordered_set<int>set;
        
        //creating frequency array
        for(auto ch:s)
        {
            freq[ch-'a']++;
        }
        
        //checking if frequency is already present
        for(int i=0;i<26;i++)
        {
            while(freq[i] && set.find(freq[i]) != set.end())
            {
                freq[i]--;
                ans++;
            }
            set.insert(freq[i]);
        }
        
        return ans;
    }
};