class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size(), k = grid[0].size();
        
        map<vector<int>, int>m;
        
//         storing the rows in the map
        for(int i=0;i<n;i++)
            m[grid[i]]++;
        
        for(int i=0;i<k;i++)
        {
//             store the columns into a vector for the comparison purpose
            vector<int>col;
            
            for(int j=0;j<n;j++)
                col.push_back(grid[j][i]);
            
//             finding the number of times the col has occured as row
            ans += m[col];
        }
        
        return ans;
    }
};