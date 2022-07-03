class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        for(int i=0;i<n;i++)
        {
            unordered_map<int,int>m;
            for(int k=1;k<=n;k++)
                m[k]++;
            
            for(int j=0;j<n;j++){
                m.erase(matrix[i][j]);
            }
            if(m.size() != 0)
                return false;
        }
        
        for(int i=0;i<n;i++)
        {
            unordered_map<int,int>m;
            for(int k=1;k<=n;k++)
                m[k]++;
            for(int j=0;j<n;j++){
                m.erase(matrix[j][i]);
            }
            if(m.size() != 0)
                return false;
        }
        
        return true;
    }
};