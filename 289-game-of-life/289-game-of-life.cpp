class Solution {
public:
    void gameOfLife(vector<vector<int>>& b) {
        int m=b.size();
        int n=b[0].size();
        
        vector<vector<int>>copy(m,vector<int>(n));
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                copy[i][j]=b[i][j];
            }
        }
        
         for(int i=0;i<m;i++)
        {
            
            for(int j=0;j<n;j++)
            {
                 int ct=0;
                if(i!=m-1 && b[i+1][j]==1)
                    ct++;
                if(i!=0 && b[i-1][j]==1)
                    ct++;
                if(j!=n-1 && b[i][j+1]==1)
                    ct++;
                if( j!=0 && b[i][j-1]==1)
                    ct++;
                if(i!=0 && j!=0 && b[i-1][j-1]==1)
                    ct++;
                if (i!=0 && j!=n-1 && b[i-1][j+1]==1)
                    ct++;
                if(i!=m-1 && j!=n-1 && b[i+1][j+1]==1)
                    ct++;
                if( i!=m-1 && j!=0 && b[i+1][j-1]==1)
                    ct++;
                
                if(ct<2)
                 copy[i][j]=0;
             else if(ct>3)
                 copy[i][j]=0;
             else if(ct==3)
                 copy[i][j]=1;
            }
         }
        
         for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                b[i][j]=copy[i][j];
            }
         }
    }
};