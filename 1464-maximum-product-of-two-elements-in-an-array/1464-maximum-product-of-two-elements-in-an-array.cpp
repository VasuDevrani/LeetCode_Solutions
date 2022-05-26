class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int>q(nums.begin(),nums.end());
        int a=q.top();
        q.pop();
        
        return (a-1)*(q.top()-1);
    }
};