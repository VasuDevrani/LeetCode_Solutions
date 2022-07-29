// The solution to this ques is quite intuitive and based on dfs traversal technique you might have studied in graphs or trees

// In the question, one can easily point that ques demands looking for all the ones present around a 1 and give the sum of all of them

// dfs traversal

// Here, consider 1s as unvisited nodes and 0s as visited nodes, if a node is unvisited we must visit it and find all the nodes around it that are unvisited as well

// also one should ensure marking them as visited (= 0) later on, to prevent recounting during the array traversal

class Solution {
public:
    
    int visitThePlace(vector<vector<int>>& grid, int i, int j, int n, int m)
    {   
        if(i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == 1){
//         mark as visited
            grid[i][j] = 0;
            
            // find other nodes around it
            return 1 + visitThePlace(grid, i+1, j, n, m) + visitThePlace(grid, i, j+1, n, m) + visitThePlace(grid, i-1, j, n, m) + visitThePlace(grid, i, j-1, n, m);
        }
        return 0;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int mx_area = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 1)
                    mx_area = max(mx_area, visitThePlace(grid, i, j, n, m));
            }
        }
        
        return mx_area;
    }
};