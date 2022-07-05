class Solution {
public:
    
    int BotUp(vector<vector<int>>v, int n)
    {
        vector<vector<int>>dp(n, vector<int>(n, 0));
        
        for(int i=0;i<n;i++)
            dp[0][i] = v[0][i];
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int ans = INT_MAX;
                
                for(int k=0;k<n;k++)
                {
                    if(k == j)
                        continue;
                    ans = min(ans, dp[i-1][k]);
                }
                
                dp[i][j] = ans + v[i][j];
            }
        }
        
        int mn =INT_MAX;
        for(int i=0;i<n;i++)
            mn = min(mn, dp[n-1][i]);
        
        return mn;
    }
    
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        
        return BotUp(grid, n);
    }
};