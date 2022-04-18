class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int row=mat.size();
        int col=mat[0].size();
        
        for(int i=0;i<row;i++)
        {
            vector<int>temp;
            int j=0,k=i;
            
            while(k<row && j<col)
            {
                temp.push_back(mat[k][j]);
                j++;
                k++;
            }
            sort(temp.begin(),temp.end());
            
            k=i;
            j=0;
            int a=0;
            while(k<row && j<col)
            {
                mat[k][j]=temp[a];
                a++;;
                j++;
                k++;
            }
        }
            
            for(int i=1;i<col;i++)
        {
            vector<int>temp;
            int j=0,k=i;
            
            while(k<col && j<row)
            {
                temp.push_back(mat[j][k]);
                j++;
                k++;
            }
            sort(temp.begin(),temp.end());
            
            k=i;
            j=0;
            int a=0;
            while(k<col && j<row)
            {
                mat[j][k]=temp[a];
                a++;;
                j++;
                k++;
            }
              
        }
            return mat;
    }
};