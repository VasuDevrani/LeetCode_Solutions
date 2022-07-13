class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& val) {
        int n = val.size();
        
        int mx = INT_MIN, mx_ind = 0, temp = val[0];
        
        vector<int>dp(n, 0);
        
        dp[0] = val[0];
        for(int i=1;i<n;i++)
        {   
            dp[i] = val[i] + i;
            
            mx = max(mx, dp[mx_ind] + val[i] - i);
            
            if(dp[i] > temp){
                mx_ind = i;
                temp = dp[i];
            }
        }
        
        return mx;
    }
};