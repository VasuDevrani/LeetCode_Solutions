class Solution {
public:
    
    bool isVowel(char c)
    {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return true;
        else
            return false;
    }
    
    int maxVowels(string s, int k) {
        int i = 0, j = 0, ct = 0, ans = 0;
        
        while(j < s.length())
        {
            if(isVowel(s[j]))
                ct++;
            if(j-i+1 == k)
            {
                ans = max(ans, ct);
                if(isVowel(s[i]))
                    ct--;
                i++;
            }
            j++;
        }
        ans = max(ans, ct);
        
        return ans;
    }
};