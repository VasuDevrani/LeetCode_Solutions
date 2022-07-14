class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        
        int ans = 0;
        for(int i=0;i<n;i++)
            ans += mat[i][0];
        
        for(int j=1;j<m;j++)
            ans += mat[0][j];
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(mat[i][j] != 0){
                    mat[i][j] = min(mat[i-1][j], min(mat[i-1][j-1], mat[i][j-1])) + 1;
                    ans += mat[i][j];
                }
            }
        }
        
        return ans;
    }
};