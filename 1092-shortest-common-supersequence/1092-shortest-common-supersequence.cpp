class Solution {
public:
    
    string createString(vector<vector<int>>dp, string s1, string s2, int n, int m)
    {
        string ans = "";
        
        int i = n, j = m;
        while(i > 0 && j > 0)
        {
            if(s1[i-1] == s2[j-1])
            {
                ans = s1[i-1] + ans;
                i--;
                j--;
            }
            else
            {
                if(dp[i-1][j] > dp[i][j-1])
                {
                    ans = s1[i-1] + ans;
                    i--;
                }
                else
                {
                    ans = s2[j-1] + ans;
                    j--;
                }
            }
        }
        
        while(i != 0){
            ans = s1[i-1] + ans;
            i--;
        }
        while(j != 0){
            ans = s2[j-1] + ans;
            j--;
        }
        
        return ans;
    }
    
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.length(), m = str2.length();
        
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(str1[i-1] == str2[j-1])
                    dp[i][j] =  dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return createString(dp, str1, str2, n, m);
    }
};