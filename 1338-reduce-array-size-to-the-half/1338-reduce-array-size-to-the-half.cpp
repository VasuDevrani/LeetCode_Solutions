class Solution {
public:
    
    bool compare(int a, int b)
    {
        return a < b;
    }
    
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int>m;
        
        for(int i=0;i<arr.size();i++)
        {
            m[arr[i]]++;
        }
        
        vector<pair<int,int>>v;
        for(auto x:m)
        {
            v.push_back(make_pair(x.second,x.first));
        }
        
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        
        int ct = 0, sum = 0;
        for(int i=0;i<v.size();i++)
        {
            sum += v[i].first;
            cout<<v[i].first<<" ";
            ct++;
            if(sum >= arr.size()/2)
                return ct;
        }
        return 0;
    }
};