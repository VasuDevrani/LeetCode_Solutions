class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int>m;
        
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        int sum=0;
        for(auto x:m)
        {
            if(x.second==1)
                sum+=x.first;
        }
        
        return sum;
    }
};