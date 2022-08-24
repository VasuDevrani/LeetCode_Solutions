class Solution {
public:
    
    int getFirstOcc(vector<int>nums, int t)
    {
        int n = nums.size()-1;
        int s = 0, e = n, f = INT_MAX;
        
        while(s <= e){
            int mid = s + (e - s)/2;
            
            if(nums[mid] == t){
                f = mid;
                e = mid - 1;
            }
            else if(nums[mid] > t)
                e = mid - 1;
            else 
                s = mid + 1;
        }
        if(f == INT_MAX)
            return -1;
        return f;
    }
    
    int getLastOcc(vector<int>nums, int t)
    {
        int n = nums.size()-1;
        int s = 0, e = n, l = INT_MAX;
        
        while(s <= e){
            int mid = s + (e - s)/2;
            
            if(nums[mid] == t){
                l = mid;
                s = mid + 1;
            }
            else if(nums[mid] > t)
                e = mid - 1;
            else 
                s = mid + 1;
        }
        if(l == INT_MAX)
            return -1;
        return l;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int>ans;
        ans.push_back(getFirstOcc(nums, target));
        ans.push_back(getLastOcc(nums, target));
        
        return ans;
    }
};