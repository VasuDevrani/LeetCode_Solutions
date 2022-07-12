class Solution {
public:
    
    int ansRecur(int n, vector<int>cuts, int i, int j, vector<vector<int>>&dp)
    {
//         base case
        if(j < i)
            return 0;
        if(j == i)
            return cuts[j+1] - cuts[i-1];
        
//         recursive case
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int cost = INT_MAX;
        
        for(int k=i;k<=j;k++)
        {
            int temp = cuts[j+1] - cuts[i-1] + ansRecur(n, cuts, i, k-1, dp) + ansRecur(n, cuts, k+1, j, dp);
            cost = min(cost, temp);
        }
        
        return dp[i][j] = cost;
    }
    
    int BotUp(vector<int>cuts, int m)
    {
        vector<vector<int>>dp(m, vector<int>(m, 0));
        
        for(int i=1;i<=m-2;i++)
        {
            dp[i][i] = cuts[i+1] - cuts[i-1];
        }
        
        for(int i=m-2;i>=1;i--)
        {
            for(int j=i+1;j<=m-2;j++)
            {
                int cost = INT_MAX;
        
                for(int k=i;k<=j;k++)
                {
                    int temp = cuts[j+1] - cuts[i-1] + dp[i][k-1] + dp[k+1][j];
                    cost = min(cost, temp);
                }

                dp[i][j] = cost;
            }
        }
        
        return dp[1][m-2];
    }
    
    int minCost(int n, vector<int>& cuts) {
        
//         insert 0 start and n at end
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        
        int m = cuts.size();
        sort(cuts.begin(), cuts.end());
        
        // vector<vector<int>>dp(m, vector<int>(m, -1));
        // return ansRecur(n, cuts, 1, m-2, dp);
        
        return BotUp(cuts, m);
    }
};