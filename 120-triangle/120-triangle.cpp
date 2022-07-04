class Solution {
public:
    
//     int getMinRecursive(vector<vector<int>>triangle, int j, int i, int n)
//     {
// //         base case
//         if(i > n)
//             return 0;
//         if(i == n)
//            return min(triangle[i][j], triangle[i][j+1]);
        
// //         recursive case
//         int left = triangle[i][j] + getMinRecursive(triangle, j, i+1, n);
//         int right = triangle[i][j+1] + getMinRecurisve(triangle, j+1, i+1, n);
        
//         return min(right, left);
//     }
    
    int BotUp(vector<vector<int>>triangle, int n)
    {
        vector<vector<int>>dp(n, vector<int>(n, 0));
        
        for(int i=0;i<n;i++)
            dp[n-1][i] = triangle[n-1][i];
        
        for(int i=n-2;i>=0;i--)
        {
            for(int j=i;j>=0;j--)
            {
                int right = triangle[i][j] + dp[i+1][j];
                int left = triangle[i][j] + dp[i+1][j+1];
                
                dp[i][j] = min(right, left);
            }
        }
        return dp[0][0];
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        
        // return triangle[0][0] + getMinRecursive(triangle, 0, 1, n-1);
        
        return BotUp(triangle, n);
    }
};