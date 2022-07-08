class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        
        for(int i=0;i<n;i++)
        {
            int sum = 0, j = 0;
            while(j < m && mat[i][j] != 0)
            {
                sum += mat[i][j];
                j++;
            }
            q.push(make_pair(sum, i));
        }
        
        vector<int>ans;
        while(k--)
        {
            ans.push_back(q.top().second);
            q.pop();
        }
        
        return ans;
    }
};