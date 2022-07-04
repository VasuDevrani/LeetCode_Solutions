class Solution {
public:
    
    int Recursive(int r, int c, vector<vector<int>>grid)
    {
//         base case
        if(grid[r][c] == 1)
            return 0;
        if(r == 0 && c == 0)
            return 1;
        if(r < 0 || c < 0)
            return 0;
        
//     recursive case
        
        int top = Recursive(r-1, c, grid);
        int left = Recursive(r, c-1, grid);
        
        return top + left;
    }
    
        int TopBot(int r, int c, vector<vector<int>>grid, vector<vector<int>>&dp)
    {
//         base case
        if(r < 0 || c < 0)
            return 0;
        if(grid[r][c] == 1)
            return 0;
        if(r == 0 && c == 0)
            return 1;
        
//     recursive case
        if(dp[r][c] != -1)
            return dp[r][c];
        
        int top = TopBot(r-1, c, grid, dp);
        int left = TopBot(r, c-1, grid, dp);
        
        return dp[r][c] = top + left;
    }
    
    int BotUp(vector<vector<int>>grid, int m, int n){
        vector<vector<int>>dp(m, vector<int>(n, 0));
        
        if(grid[0][0] == 1)
            return 0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
            {
                if(i == 0 && j == 0)
                    dp[0][0] = 1;
                else if(grid[i][j] == 1)
                    dp[i][j] = 0;
                else{
                    int down = 0, right = 0;
                    if(i > 0)
                        down = dp[i-1][j];
                    if(j > 0)
                        right = dp[i][j-1];
                    
                    dp[i][j] = right + down;    
                }
            }   
        }
        return dp[m-1][n-1];
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& og) {
        int m = og.size();
        int n = og[0].size();
        
        // return recursive(m-1, n-1, og);
        
        vector<vector<int>>dp(m, vector<int>(n, -1));
        // return TopBot(m-1, n-1, og, dp);
        
        return BotUp(og, m, n);
    }
};