class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int i, j;
        int n = matrix.size(), m = matrix[0].size();
        
        priority_queue<int,vector<int>,greater<int>>q;

//         column xors
        for(i=0;i<n;i++)
        {
            for(j=1;j<m;j++)
            {
                matrix[i][j] = matrix[i][j-1] ^ matrix[i][j];
            }
        }
        
//         row xors
        for(i=0;i<m;i++)
        {
            for(j=1;j<n;j++)
            {
                matrix[j][i] = matrix[j-1][i] ^ matrix[j][i];
            }
        }
        
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(q.size() < k)
                    q.push(matrix[i][j]);
                else
                {
                   if(matrix[i][j] > q.top())
                   {
                       q.pop();
                       q.push(matrix[i][j]);
                   }
                }
            }
        }
        
        return q.top();
    }
};