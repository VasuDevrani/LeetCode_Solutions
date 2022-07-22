class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& block, vector<int>& nb) {
        int n = block.size();
        
        int left[n+1], right[n+1];
        
        for(int i=0;i<n;i++)
        {
            left[i] = block[i][0];
            right[i] = block[i][1];
        }
        
        left[n] = nb[0];
        right[n] = nb[1];
        
        sort(left, left+n+1);
        sort(right, right+n+1);
        
        int i = 0, j = 0;
        
        vector<vector<int>>ans;
        while(j <= n && i <= n)
        {
            int k = i+1;
            if(i < n){
                while(j <= n && k <= n && right[j] >= left[k])
                {
                    j++;
                    k++;
                }
            }
            
            vector<int>v;
            v.push_back(left[i]);
            v.push_back(right[j]);
            ans.push_back(v);
            
            i = k;
            j++;
        }
        
        return ans;
    }
};