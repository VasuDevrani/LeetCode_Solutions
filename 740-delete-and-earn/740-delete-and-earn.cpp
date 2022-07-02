class Solution {
public:
    
    int getAns(vector<pair<int,int>>v, int i, vector<int>&dp)
    {
//         base case
        if(i < 0)
            return 0;
        if(i == 0)
            return (v[0].first * v[0].second);
        
        if(dp[i] != -1)
            return dp[i];
        
//         recursive case
        if(v[i-1].first == v[i].first - 1){
            int incl = getAns(v, i-2, dp) + (v[i].second * v[i].first);
            int excl = getAns(v, i-1, dp);

            return dp[i] = max(incl, excl);
        }
        else{
            return dp[i] = getAns(v, i-1, dp) + (v[i].second * v[i].first);
        }
    }
    
    int deleteAndEarn(vector<int>& nums) {
        
        if(nums.size() == 1)
            return nums[0];
        
        unordered_map<int,int>m;
        
        int n = nums.size();
        for(int i=0;i<n;i++)
            m[nums[i]]++;
        
        vector<pair<int,int>>arr;
        
        for(auto x:m)
            arr.push_back(make_pair(x.first, x.second));
        
        sort(arr.begin(), arr.end());
        
        vector<int>dp(arr.size(), -1);
        
        getAns(arr, arr.size()-1, dp);
        
        return dp[arr.size()-1];
    }
};