class Solution {
public:
    vector<vector<int>> generate(int r) {
//         space optimized bottom up dp
        vector<vector<int>>ans;
        
        vector<int>prev = {1};
        
        ans.push_back(prev);
        
        for(int i=1;i<r;i++)
        {
            int n = i+1;
            vector<int>cur(n, 1);
            for(int j=1;j<n-1;j++)
            {
                cur[j] = prev[j-1] + prev[j];
            }
            prev = cur;
            ans.push_back(cur);
        }
        
        return ans;
    }
};