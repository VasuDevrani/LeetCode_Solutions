class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int ct = 0;
        int pre = 1;
        
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i] != pre)
            {
                int diff = k - ct - 1;
                ct += arr[i] - pre;
                if(ct >= k)
                    return pre + diff;
            }
            pre = arr[i] + 1;
        }
        if(ct != k)
            return pre + k - ct - 1;
        return 0;
    }
};