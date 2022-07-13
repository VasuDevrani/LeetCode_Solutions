class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int l = s.length();
        
//         a dp array which holds the end index of previously found string from the array
        vector<bool>dp(l+1, false);
        
        dp[0] = true;
        for(int i=1;i<=l;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(dp[j] && (find(wordDict.begin(), wordDict.end(), s.substr(j, i-j)) != wordDict.end()))
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[l];
    }
};