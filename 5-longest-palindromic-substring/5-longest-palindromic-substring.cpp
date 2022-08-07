class Solution {
public:
    
    string BotUp(string s, string s1, int n)
    {
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
        
        int mx = 0;
        string ans;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1] == s1[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    
//                  got a substring, check if its palindrome
                    if(dp[i][j] > mx)
                    {
                        string temp = s.substr(i-dp[i][j], dp[i][j]) ;
                        
                        string revtemp = string(temp.rbegin(),temp.rend());
                        
                        if(revtemp == temp)
                        {
                            mx = dp[i][j] ;
                            ans = temp ;
                        }
                    }
                }
            }
        }
        
        return ans;
    }
    
    string longestPalindrome(string s) {
        int n = s.length();
        
        string s1 = s;
        reverse(s1.begin(), s1.end());
        
        return BotUp(s, s1, n);
    }
};