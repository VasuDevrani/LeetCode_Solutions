class Solution {
public:
    int minimumTotal(vector<vector<int>>& tri) {
        
//         bottom up approach to get the min_sum path
        
//         first loop traverses from second last row 
        for(int i=tri.size()-2;i>=0;i--)
        {
//             this loops keeps storing the min values from lower rows
            for(int j=0;j<tri[i].size();j++)
            {
                tri[i][j] = tri[i][j] + min(tri[i+1][j+1], tri[i+1][j]);
            }
        }
            
//         finally the lowest sum values get collected at top and we return top
        return tri[0][0];
    }
};