class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        
        int r=grid.size();
        int c=grid[0].size();
        
        if(r<=1 && c<=1)
            return grid;
        
        vector<vector<int>>ans(r,vector<int>(c));
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                int I=i,J=j;
                for(int t=0;t<k;t++)
                {
                    if(J==c-1 && I!=r-1)
                    {
                        I++;
                        J=0;
                    }
                    else if(I==r-1 && J==c-1)
                    {
                        I=0;
                        J=0;
                    }
                    else
                        J++;
                }
                ans[I][J]=grid[i][j];
            }
        }
        return ans;
        
    }
};