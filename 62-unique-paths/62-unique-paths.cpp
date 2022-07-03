class Solution {
public:
    
//     time complexity of solution is O(m*n) in worst case
//     space complexity is O(m-1 + n-1) + O(m*n) 
    
    int getTopBot(int r, int c, vector<vector<int>>&dp)
    {
//         base case
        if(r == 0 && c == 0)
            return 1;
        if(r < 0 || c < 0)
            return 0;
        
//         recursive case
        if(dp[r][c] != -1)
            return dp[r][c];
        
        return dp[r][c] = getTopBot(r-1, c, dp) + getTopBot(r, c-1, dp);
    }
    
    int getBotUp(int m, int n)
    {
        vector<vector<int>>dp(m, vector<int>(n));
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i == 0 && j == 0)
                    dp[0][0] = 1;
                else{
                    int up = 0, down = 0;
                    if(i > 0)
                        up = dp[i-1][j];
                    if(j > 0)
                        down = dp[i][j-1];
                    
                    dp[i][j] = up + down;
                }
            }
        }
        
        return dp[m-1][n-1];
    }
    
    int uniquePaths(int m, int n) {
        
        vector<vector<int>>dp(m, vector<int>(n, -1));
        // return getTopBot(m-1, n-1, dp);
        return getBotUp(m, n);
    }
};