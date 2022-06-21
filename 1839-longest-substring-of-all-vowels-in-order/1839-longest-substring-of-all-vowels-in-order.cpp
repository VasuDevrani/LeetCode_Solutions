class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int i = 0, j = 0, ans = 0;
        char prev;
        unordered_map<char,int>m;
        
        while(j <= word.length())
        {
            if(prev > word[j] || j == word.length())
            {
//                 change
                if(m.size() == 5)
                    ans = max(ans, j-i);
                m.clear();
                i = j;
            }
            m[word[j]]++;
            prev = word[j];
            j++;
        }
        
        return ans;
    }
};