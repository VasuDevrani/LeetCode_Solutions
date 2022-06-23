class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>ans;
        
//         creating a difference array to store the absolute diff
        int diff[arr.size()];
        for(int i=0;i<arr.size();i++)
            diff[i] = abs(x - arr[i]);
        
//         the map will contain order of occurence of differences in diff array
        map<int, vector<int>>m;
        for(int i=0;i<arr.size();i++)
        {
            m[diff[i]].push_back(i);
        }
        
//         finally traversing the map and getting the closest element form the index stored
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
        
//         sorting in increasing order
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};