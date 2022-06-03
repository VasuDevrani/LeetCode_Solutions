class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int>m;
        
        for(int i=0;i<arr1.size();i++)
        {
            m[arr1[i]]++;
        }
        
        vector<int>ans;
        for(int i=0;i<arr2.size();i++)
        {
            int n=m[arr2[i]];
            while(n--)
            {
                ans.push_back(arr2[i]);
            }
            m.erase(arr2[i]);
        }
        
        int i=ans.size();
        for(auto x:m)
        {
            int n=x.second;
            while(n--)
            {
                ans.push_back(x.first);
            }
        }
        
        sort(ans.begin()+i,ans.end());
        
        return ans;
    }
};