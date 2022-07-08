class Solution {
public:
    
    int lcsRecur(string s1, string s2, int n, int m)
    {
//         base case
        if(n < 0 || m < 0)
            return 0;
        
//         recursive case
        if(s1[n] == s2[m])
            return 1 + lcsRecur(s1, s2, n-1, m-1); //when the chars are equal
        else
            return max(lcsRecur(s1, s2, n-1, m), lcsRecur(s1, s2, n, m-1)); 
            //when not equal there are two possibilities
    }
    
    int TopBot(string s1, string s2, int n, int m, vector<vector<int>>&dp)
    {
//         base case
        if(n < 0 || m < 0)
            return 0;
        
//         recursive case
        
        if(dp[n][m] != -1)
            return dp[n][m];
        
        if(s1[n] == s2[m])
            return dp[n][m] = 1 + lcsRecur(s1, s2, n-1, m-1); 
            //when the chars are equal
        else
            return dp[n][m] = max(lcsRecur(s1, s2, n-1, m), lcsRecur(s1, s2, n, m-1)); 
            //when not equal there are two possibilities
    }
    
    int BotUp(string s1, string s2, int n, int m)
    {
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        
        for(int i=0;i<m+1;i++)
            dp[0][i] = 0;
        
        for(int i=0;i<n+1;i++)
            dp[i][0] = 0;
        
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1]; 
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return dp[n][m];
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(), m = text2.length();
        
//       as there are two variables m, n in the argument of recur function, dp array must be 2D
        
//         vector<vector<int>>dp(n, vector<int>(m, -1));
        
//         return TopBot(text1, text2, n-1, m-1, dp);
        
        return BotUp(text1, text2, n, m);
    }
};