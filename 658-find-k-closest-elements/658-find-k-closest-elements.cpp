class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>ans;
        
        int diff[arr.size()];
        for(int i=0;i<arr.size();i++)
            diff[i] = abs(x - arr[i]);
        
        map<int, vector<int>>m;
        for(int i=0;i<arr.size();i++)
        {
            m[diff[i]].push_back(i);
        }
        
        for(auto x:m)
        {
            for(int i=0;i<x.second.size();i++)
            {
                ans.push_back(arr[x.second[i]]);
                k--;
                if(k <= 0)
                    break;
            }
            if(k <= 0)
                break;
        }
        
        sort(ans.begin(), ans.end());
        
        return ans;
        
        
        
//         if(arr[0] >= x)
//         {
//             for(int i=0;i<k;i++)
//                 ans.push_back(arr[i]);
//             return ans;
//         }
//         else
//         {
//             int ind = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
            
//             int 
//         }
    }
};