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
    
    int uniquePathsWithObstacles(vector<vector<int>>& og) {
        int m = og.size();
        int n = og[0].size();
        
        // return recursive(m-1, n-1, og);
        
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return TopBot(m-1, n-1, og, dp);
    }
};