class Solution {
public:
    int findShortestSubArray(vector<int>& arr) {
        unordered_map<int, int>m;
        
        int mx = 0, ans = arr.size();
        
        int n = arr.size();
        for(int i=0;i<n;i++)
        {
            m[arr[i]]++;
            if(m[arr[i]] > mx)
            {
                mx = m[arr[i]];
            }
        }
        
        for(auto x: m){
            if(x.second == mx)
            {
                int left = n - 1, right = 0;
                for(int i=0;i<n;i++)
                {
                    if(arr[i] == x.first && i < left)
                        left = i;
                    if(arr[i] == x.first && i > right)
                        right = i;
                }
                if(right - left + 1 < ans)
                    ans = right - left + 1;
            }
        }
        
        return ans;
    }
};