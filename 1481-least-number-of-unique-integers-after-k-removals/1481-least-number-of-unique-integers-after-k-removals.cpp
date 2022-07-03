class Solution {
public:
    
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int,int>m;
        
        for(int i=0;i<n;i++)
            m[arr[i]]++;
        
        vector<pair<int,int>>v;
        
        for(auto x:m)
            v.push_back(make_pair(x.second, x.first));
        
        sort(v.rbegin(), v.rend());
        
        int i = v.size()-1;
        while(k != 0 && i >= 0)
        {
            if(k - v[i].first < 0)
                k = 0;
            else{
                k -= v[i].first;
                v.pop_back();
            }
            i--;
        }
        
        return v.size();
    }
};