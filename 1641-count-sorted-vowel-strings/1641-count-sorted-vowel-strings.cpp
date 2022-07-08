class Solution {
public:
    
    int countRecur(int i, int ct, string vowel)
    {
//         base case
        if(ct == 0 || i == 4)
            return 1;
        
//         recursive case
        int not_take = countRecur(i+1, ct, vowel);
        int take = countRecur(i, ct-1, vowel);
        
        return take + not_take;
    }
    
    int TopBot(int i, int ct, string vowel, vector<vector<int>>&dp)
    {
//         base case
        if(ct == 0 || i == 4)
            return 1;
        
//         recursive case
        
        if(dp[i][ct] != -1)
            return dp[i][ct];
        
        int not_take = TopBot(i+1, ct, vowel, dp);
        int take = TopBot(i, ct-1, vowel, dp);
        
        return dp[i][ct] = take + not_take;
    }
    
    int BotTop(int ct, string vowel, int n)
    {
        vector<vector<int>>dp(n, vector<int>(ct+1, 0));
        
        for(int i=0;i<n;i++)
            dp[i][0] = 1;
        
        for(int j=0;j<=ct;j++)
            dp[4][j] = 1;
        
        for(int i=3;i>=0;i--) //index
        {
            for(int j=1;j<=ct;j++) //count
            {
                int not_take = dp[i+1][j];
                int take = dp[i][j-1];

                dp[i][j] = take + not_take; 
            }
        }
        
        return dp[0][ct];
    }
    
    int countVowelStrings(int n) {
        string vowel = "aeiou";
        
        // vector<vector<int>>dp(5, vector<int>(n+1, -1));
        // return TopBot(0, n, vowel, dp);
        
        return BotTop(n, vowel, 5);
    }
};