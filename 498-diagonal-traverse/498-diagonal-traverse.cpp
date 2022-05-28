class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int row=mat.size();
        int col=mat[0].size();
        bool up=true;
        
        int i=0,j=0;
        vector<int>ans;
        while(i<row && j<col)
        {
            if(up)
            {
                while(i>0 && j<col-1)
                {
                    ans.push_back(mat[i][j]);
                    i--;
                    j++;
                }
                ans.push_back(mat[i][j]);
                if(j==col-1)
                    i++;
                else
                   j++; 
            }
            else
            {
                while(i<row-1 && j>0)
                {
                    ans.push_back(mat[i][j]);
                    i++;
                    j--;
                }
                ans.push_back(mat[i][j]);
                if(i==row-1)
                    j++;
                else
                   i++;
            }
            up=!up;
        }
        
        return ans;
    }
};