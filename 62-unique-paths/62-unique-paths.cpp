class Solution {
public:
    
    int getAns(int r, int c, vector<vector<int>>&dp)
    {
//         base case
        if(r == 0 && c == 0)
            return 1;
        if(r < 0 || c < 0)
            return 0;
        
//         recursive case
        if(dp[r][c] != -1)
            return dp[r][c];
        
        return dp[r][c] = getAns(r-1, c, dp) + getAns(r, c-1, dp);
    }
    
    int uniquePaths(int m, int n) {
        
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return getAns(m-1, n-1, dp);
    }
};