class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
//         can also be solved using set but unorderd map gives O(1)
        int ct=0;
        unordered_map<int,int>m;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(m.empty()){
                m[nums[i]]++;
                continue;
            }
            int n=nums[i];
            if(m.find(n+k)!=m.end())
                ct+=m[n+k];
            if(m.find(n-k)!=m.end())
                ct+=m[n-k];
            m[nums[i]]++;
        }
        
        return ct;
    }
};