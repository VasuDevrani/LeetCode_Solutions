class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> mp; 
        
        int i=0, sum = nums[i] , maxi = 0;
        mp[nums[i]]++;
        
        for(int j = 1; j < nums.size(); j++)
        {
            if(mp.count(nums[j])){
                maxi = max(maxi,sum);
                while(mp.count(nums[j]))
                { 
                    mp.erase(nums[i]);
                    sum-=nums[i];
                    i++;
                }
            }
            mp[nums[j]]++;
            sum+=nums[j];
        }
        maxi = max(sum,maxi);
        return maxi;
    }
};