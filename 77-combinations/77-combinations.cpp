class Solution {
public:
    
    void getAns(int k, int ct, int src, vector<vector<int>>&ans, vector<int>temp)
    {
        if(ct == k)
        {
            ans.push_back(temp);
            return;
        }
        if((k-ct) > src)
            return;
        
        if(src == 0)
            return;
        
        getAns(k, ct, src-1, ans, temp);
        temp.push_back(src);
        getAns(k, ct+1, src-1, ans, temp);
        temp.pop_back();
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        
        vector<int>temp;
        
        getAns(k, 0, n, ans, temp);
        
        return ans;
    }
};