class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int preXOR[arr.size()];
        vector<int>ans;
        
        int x=0;
        for(int i=0;i<arr.size();i++)
        {
            x=x^arr[i];
            preXOR[i]=x;
        }
        
        for(int i=0;i<queries.size();i++)
        {
            int start = queries[i][0];
            int last = queries[i][1];
            
            int n;
            if(start==0)
                n = preXOR[last];
            else
                n = preXOR[last] ^ preXOR[start-1];
            ans.push_back(n);
        }
        
        return ans;
    }
};